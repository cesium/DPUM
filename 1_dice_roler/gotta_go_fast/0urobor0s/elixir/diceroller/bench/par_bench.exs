defmodule BasicBench do
  use Benchfella

  @list File.read!("sample_input.txt") |> String.split("\n") |> List.delete("")

  bench "Single roler single execution" do
    DiceRoler.ssroler(@list)
    :ok
  end

  bench "Single roler parallel execution" do
    DiceRoler.sroler(@list)
    :ok
  end

  bench "Parallel roler parallel execution v1" do
    DiceRoler.proler(@list)
    :ok
  end

  bench "Parallel roler parallel execution v2" do
    DiceRoler.pproler(@list)
    :ok
  end
end
