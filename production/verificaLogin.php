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
  	$result;

	if ($buscaUsuario->rowcount()==0) {
		
		$result=0;
		

	}
	else{
		
		$result="Usuário encontrado";
	 	$_SESSION["senha"] =$senha;
	 	foreach ($linha as $Listar) {
     		$_SESSION["nome"]=$Listar->nome;
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