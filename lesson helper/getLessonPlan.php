<?php
$level = $_POST["level"];
$fname = $_POST["fname"];
$week = $_POST["week"];
$N = "\n";
$myfile = fopen("temp.txt", "w") or die("Unable to store");
fwrite($myfile, $level.$N.$fname.$N.$week);
fclose($myfile);
shell_exec("./a.out");
header("Location: http://bradensbay.com/lessonHelper/output.html");
?>