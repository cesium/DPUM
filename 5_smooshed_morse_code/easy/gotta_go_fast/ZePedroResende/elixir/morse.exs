defmodule Morse do
  @abc %{
    "a" => ".-",
    "b" => "-...",
    "c" => "-.-.",
    "d" => "-..",
    "e" => ".",
    "f" => "..-.",
    "g" => "--.",
    "h" => "....",
    "i" => "..",
    "j" => ".---",
    "k" => "-.-",
    "l" => ".-..",
    "m" => "--",
    "n" => "-.",
    "o" => "---",
    "p" => ".--.",
    "q" => "--.-",
    "r" => ".-.",
    "s" => "...",
    "t" => "-",
    "u" => "..-",
    "v" => "...-",
    "w" => ".--",
    "x" => "-..-",
    "y" => "-.--",
    "z" => "--..",
    "\n" => "\n"
  }

  def pmap(collection, func) do
    collection
    |> Enum.map(&Task.async(fn -> func.(&1) end))
    |> Enum.map(&Task.await/1)
  end

  def read_file(file) do
    case File.read(file) do
      {:ok, lines} ->
        lines

      {:error, _} ->
        IO.puts("Can't open " <> file)
        ""
    end
  end

  def encode(string) do
    String.downcase(string)
    |> String.graphemes()
    |> pmap(&Map.get(@abc, &1, ""))
  end

  def main() do
    System.argv()
    |> pmap(&read_file(&1))
    |> pmap(&encode(&1))
    |> IO.puts()
  end
end

Morse.main()
