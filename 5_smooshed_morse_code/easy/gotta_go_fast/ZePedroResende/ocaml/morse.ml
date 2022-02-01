let abc  = [
  'a' , ".-";
  'b' , "-...";
  'c' , "-.-.";
  'd' , "-..";
  'e' , ".";
  'f' , "..-.";
  'g' , "--.";
  'h' , "....";
  'i' , "..";
  'j' , ".---";
  'k' , "-.-";
  'l' , ".-..";
  'm' , "--";
  'n' , "-.";
  'o' , "---";
  'p' , ".--.";
  'q' , "--.-";
  'r' , ".-.";
  's' , "...";
  't' , "-";
  'u' , "..-";
  'v' , "...-";
  'w' , ".--";
  'x' , "-..-";
  'y' , "-.--";
  'z' , "--..";
  '\n' , "\n"
];;

let find x =
  match List.assoc_opt x abc with
  Some(x) -> x
  | None -> "";;


let encode x =
  let down_case = String.lowercase_ascii x in
  let to_list = List.init (String.length down_case) (String.get down_case) in
  let list = List.map (fun c -> find c ) to_list in
  String.concat "" list;;

let maybe_read_line () =
  try Some(read_line())
  with End_of_file -> None

let rec loop acc =
  match maybe_read_line () with
  | Some(line) -> loop ((encode line) :: acc)
  | None -> acc |> List.rev |> List.iter print_endline

let () = loop []
