defmodule DiceRoler do
  @moduledoc """
  Documentation for Diceroler.
  """

  def ssroler(list) do
    Stream.map list, fn(input) ->
      [n, d] = String.split(input, "d")
      Enum.reduce(1..String.to_integer(n), 0, fn(_d, acc) ->
        Enum.random(1..String.to_integer(d)) + acc
      end)
    end
  end

  def sroler(list) do
    Stream.map list, fn(x) -> roler(x) end
  end

  def pproler(list) do
    t = ParallelTask.new
    pproler_a(t, list)
    |> Enum.reduce(0, fn({_k, v}, acc) -> v + acc end)
  end

  defp pproler_a(tsk, []) do
    tsk
    |> ParallelTask.perform
  end

  defp pproler_a(tsk, list) do
    tsk
    |> ParallelTask.add(Kernel.hd(list), fn -> roler(Kernel.hd(list)) end)
    |> pproler_a(Kernel.tl(list))
  end

  def proler(list) do
    Parallel.map list, fn(x) -> roler(x) end
  end

  def roler(input) do
    [n, d] = String.split(input, "d")
    n = String.to_integer(n)
    d = String.to_integer(d)
    t = ParallelTask.new

    tasker(t, n, d)
  end

  defp tasker(tsk, 0, _dice) do
    tsk
    |> ParallelTask.perform 
    |> Enum.reduce(0, fn({_k, v}, acc) -> v + acc end)
  end

  defp tasker(tsk, number, dice) do
    tsk
    |> ParallelTask.add(number, fn -> Enum.random(1..dice) end)
    |> tasker(number-1, dice)
  end

  defp read_f(path) do
    path
    |> File.stream!
    |> Enum.to_list
    |> Enum.map(fn x -> String.trim x end)
  end

  def rmeasure(path) do
    Benchmark.measure(fn -> read_f(path) |> ssroler |> Enum.sum end)
    Benchmark.measure(fn -> read_f(path) |> sroler end)
    Benchmark.measure(fn -> read_f(path) |> pproler end)
    #Benchmark.measure(fn -> read_f(path) |> proler end)
  end
end
