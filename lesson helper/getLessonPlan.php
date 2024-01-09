<?php
$level = $_POST["level"];
$fname = $_POST["fname"];
$week = $_POST["week"];
$N = "\n";
$myfile = fopen("temp.txt", "w") or die("Unable to store");
fwrite($myfile, $level.$N.$fname.$N.$week);
fclose($myfile);
$resp = shell_exec("python3 main.py");
$myfile = fopen("userHistory.txt", "w") or die("Unable to store");
fwrite($myfile, $resp);
fclose($myfile);
header("Location: http://bradensbay.com/lessonHelper/output.html");
?>