<?php
	
	//include ("conexao.php");
	//$pdo=conectar();
	require_once "conexao.php";

	//$pdo=conectar();
	$email=$_POST['email'];
	$nome=$_POST['nome'];
	$senha=$_POST['senha'];
	//$razaoSocial=$_POST['razaoSocial'];
	//$nomeFantasia=$_POST['nomeFantasia'];
	//$cpf=$_POST['cpf'];
	//$cnpj=$_POST['cnpj'];
	//echo $nome ;
	//echo "string";


	//$senha='91645709';
	//mysql_query();
	$inserir=$pdo->prepare("INSERT INTO pessoa(nome,email,senha)VALUES(?,?,?)");
	$dados = array($nome,$email,$senha);
	//$inserir->bindValue(":nome",$nome);

	$cadastrar=$inserir->execute($dados);
	//echo "var cadasrar ".$cadastrar."<br/>";
	$result;
	if($cadastrar){

		
		$result=1;
		//header("Location:login.html");
		
	}else{
		$result=0;
		

	}
?>
<html>
<head>
	<title></title>
	<script type="text/javascript">
		function teste(){
			var resultado = "<?php echo $result; ?>";
			if (resultado==0) {
				alert("Erro no cadstro! Tente Novamente");
	 			window.location.href="login.html";
			}
			else {
				alert("Cadastro realizado com sucesso!");
				window.location.href="login.html";
			}
		}
	</script>
</head>
<body onload="teste()">

</body>
</html>