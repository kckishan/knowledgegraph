<!DOCTYPE html>
<html>
<head>
<title><Knowledge Graph Search></title>
 <style>
body
{
background-image:url('s.PNG');
background-repeat:no-repeat;
background-position:100% -150%;
margin-left:450px;
margin-down:350px;
}
</style>
</head>
<body>
             Knowlegde Graph Search
<form method="post" action="search.php">
<input type="text" size="20" maxlength="255" name="input1" />
<input type="text" size="20" maxlength="255" name="input2" /> <br>
<input type="submit" value="Search" />

</form>
<?php
if(empty($_POST["input1"]) || empty($_POST["input2"]))
echo "<h4>please enter both fields</h4>";
if(!empty($_POST["input1"]) && !empty($_POST["input2"]))
{
echo "<h4>Result</h4>";
exec("merge.exe");
$input1=$_POST["input1"];
$input2=$_POST["input2"];
$result=shell_exec("Main.exe"." ".$input1." ".$input2);
$file = fopen("result.txt", "r") or exit("Unable to open file!");
//Output a line of the file until the end is reached
while(!feof($file))
  {
  echo "<b>".fgets($file)."</b>"."<br>";
  }
fclose($file);
//$output = file_get_contents('http://127.0.0.1/search/result.txt');
//echo $output;
//echo $results;
//unset($results);
}
?>
</body>
</html>
