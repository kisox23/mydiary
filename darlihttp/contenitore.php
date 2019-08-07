<html>
<head><title>CONTENITORE</title>
<link href="/favicon.ico" rel="icon">
</head>
<style>
	html {display: table; margin: auto; height: 100%;}
	h1 {text-align: center; margin-top: 50px; font-family: serif; font-variant: inherit; font-size: 30px;
	font-family: monospace; }
	body {background-color: lemonchiffon; display: table-cell; vertical-align: middle; height: 100%;}
	input {font-style: oblique; background-color: lightpink; border-radius: 20px; border-width: 5px; border-color: black;
	display: block; margin: auto; margin-top: 180px; height: 100px; width: 300px;
	font-size: 40px; text-align: center; }
	textarea {display: block; margin: 0 auto; border-width: 3px;}
</style>
<body>
	<h1>Qui puoi scrivere tutto quello che ti passa per la testa!</h1>
	<h1>A partire da lamentele a dichiarazioni, cose dolci, cose stronze, cose che ti succedono, osservazioni.</h1>
	<form method="post" name="formm">
	<textarea id="txtarea" cols="100" rows="5" name="txtarea"></textarea>
	<input name="tochange" id="grr" type="submit" value="INVIA" onclick="change()"></form>
</body>
<script>
	function change() {
		document.getElementById("grr").name = "formm";
	}
</script>
<?php
if (isset($_POST['formm'])) {
	savetxt();
}
function savetxt() {
	$pth = "/srv/http/cont.txt";
	$line = "\n<----------------------------------------------->";
	$file = fopen($pth, "a");
	$text = $_POST["txtarea"];
	file_put_contents($pth, $text, FILE_APPEND);
	file_put_contents($pth, $line, FILE_APPEND);
	fclose($file);
	echo "<script>window.close();</script>";
}
?>
</html>