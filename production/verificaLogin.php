
<?php 
session_start();
  require_once "conexao.php";
  $email=$_POST['email'];
  $senha=$_POST['senha'];
  $buscaUsuario=$pdo->prepare("SELECT * FROM pessoa WHERE email ='$email' AND senha='$senha'" );
  //$buscaUsuario->bindValue(":id",1,PDO::PARAM_INT);
  $buscaUsuario->execute();
  $linha=$buscaUsuario->fetchAll(PDO::FETCH_OBJ);
  	//echo $buscaUsuario->rowcount()."<br/>";

	if ($buscaUsuario->rowcount()==0) {
		
		$result=0;
	}
	else{
		$result=1;
	 	$_SESSION["senha"] =$senha;
	 	$_SESSION['logado']=true;
	 	foreach ($linha as $Listar) {
            $_SESSION["nome"]=$Listar->nome;
            $_SESSION["idUsuario"]=$Listar->id;
            header("Location:index.php");
      
     	}
	}
?>
<html>
<head>
	<title></title>

	<script type="text/javascript">
		function teste(){
			var resultado = "<?php echo $result; ?>";
			if (resultado==0) {
				alert("Usuário ou senha incorretos! Tente Novamente");
	 			window.location.href="login.html";
			}
		}
	</script>
</head>
<body onload="teste()">

</body>
</html>