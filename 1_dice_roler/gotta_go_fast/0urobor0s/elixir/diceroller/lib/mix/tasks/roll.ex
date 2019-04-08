defmodule Mix.Tasks.Roll do
  use Mix.Task

  def run(args) do
    cond do
      length(args) == 0 ->
        Mix.shell.info "Needs to receive atleast one file path ."
      true ->
        create(args)
    end
  end

  defp create(path) do
    Mix.Task.run "app.start"
    path
    |> File.stream!
    |> Enum.to_list
    |> Enum.map(fn x -> String.trim x end)
    |> DiceRoler.pproler
    #|> Enum.sum
    |> IO.puts
    #|> Enum.each(fn x -> IO.puts x end)
  end
end
