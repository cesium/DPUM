import scala.io.StdIn

object Morse {
  def main(args: Array[String]): Unit = {
    var abc: Map[Char, String] = Map('a' -> ".-",
      'b' -> "-...",
      'c' -> "-.-.",
      'd' -> "-..",
      'e' -> ".",
      'f' -> "..-.",
      'g' -> "--.",
      'h' -> "....",
      'i' -> "..",
      'j' -> ".---",
      'k' -> "-.-",
      'l' -> ".-..",
      'm' -> "--",
      'n' -> "-.",
      'o' -> "---",
      'p' -> ".--.",
      'q' -> "--.-",
      'r' -> ".-.",
      's' -> "...",
      't' -> "-",
      'u' -> "..-",
      'v' -> "...-",
      'w' -> ".--",
      'x' -> "-..-",
      'y' -> "-.--",
      'z' -> "--..",
      '\n' -> "\n"
    )
    var line = ""
    while({line = StdIn.readLine(); line != null }) {
      println(line.toList.map(x => abc.getOrElse(x,"") ).mkString(""))
    }
  }

}
