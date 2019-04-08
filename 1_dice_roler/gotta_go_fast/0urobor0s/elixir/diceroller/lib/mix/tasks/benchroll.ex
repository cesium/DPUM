defmodule Mix.Tasks.BenchRoll do
  use Mix.Task

  def run(args) do
    #File.read!("input.txt") 
    #|> String.split("\n") 
    #|> List.delete("")
    #|> DiceRoler.sroler
    cond do
      length(args) == 0 ->
        Mix.shell.info "Needs to receive atleast one file path ."
      true ->
        #Benchmark.measure(fn -> create(args) end)
        create(args)
    end
  end

  defp create(path) do
    Mix.Task.run "app.start"
    res = path
    |> File.stream!
    |> Enum.to_list
    |> Enum.map(fn x -> String.trim x end)
    #|> DiceRoler.sroler
    Benchmark.measure(fn -> DiceRoler.sroler(res) end)
  end
end
