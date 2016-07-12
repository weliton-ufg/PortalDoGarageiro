<?php
session_start();	
session_destroy();
?>
<html>
<head>
	<title></title>
	<script type="text/javascript">
	function logout(){
	 window.location.href="login.html";
	}
	</script>
</head>
<body onload="logout()">
</body>
</html>