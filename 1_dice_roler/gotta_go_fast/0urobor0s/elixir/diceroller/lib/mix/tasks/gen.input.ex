defmodule Mix.Tasks.Gen.Input do
  use Mix.Task

  def run(args) do
    cond do
      length(args) == 0 ->
        Mix.shell.info "Needs to receive a number."
      true ->
        create(args)
    end
  end

  defp create(number) do
    Mix.Task.run "app.start"
    number
    |> List.first
    |> String.to_integer
    |> for_c
  end

  defp for_c(number) do
    Enum.each 1..number, fn(_) ->
      IO.puts "#{Enum.random(1..100)}d#{Enum.random(2..100)}"
    end
  end
end
