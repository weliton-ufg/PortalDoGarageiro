<?php
	
	//include ("conexao.php");
	//$pdo=conectar();
	require_once "conexao.php";

	//$pdo=conectar();
	$email=$_POST['email'];
	$nome=$_POST['nome'];
	$senha=$_POST['senha'];
	$cnpj=$_POST['cnpj'];
	$nomeFantasia=$_POST['nomeFantasia'];
	//$razaoSocial=$_POST['razaoSocial'];
	//$nomeFantasia=$_POST['nomeFantasia'];
	//$cpf=$_POST['cpf'];
	//$cnpj=$_POST['cnpj'];
	//echo $nome ;
	//echo "string";
	$buscaLoja=$pdo->prepare("SELECT * FROM loja WHERE cnpjLoja='".$cnpj."'" );
	$buscaLoja->execute();
	$linha=$buscaLoja->fetchAll(PDO::FETCH_OBJ);

  if($buscaLoja->rowcount()==0) {

		$inserirLoja=$pdo->prepare("INSERT INTO loja(cnpjLoja,nomeFantasia)VALUES(?,?)");
		$dadosLoja= array($cnpj,$nomeFantasia);
		$cadastrarLoja=$inserirLoja->execute($dadosLoja);

		//se cadastro da loja der certo
		if ($cadastrarLoja) {
			//verifica se usuario ja está cadastrado
			$buscaUsuario=$pdo->prepare("SELECT * FROM pessoa WHERE email='$email' AND cnpj='$cnpj'" );
			$buscaUsuario->execute();
			$linha=$buscaUsuario->fetchAll(PDO::FETCH_OBJ);
			// se usuario nao estive cadastrado
			if ($buscaUsuario->rowcount()==0) {	
				$inserir=$pdo->prepare("INSERT INTO pessoa(nome,email,senha,cnpj,nivel)VALUES(?,?,?,?,?)");
				$dados = array($nome,$email,$senha,$cnpj,1);
				//$inserir->bindValue(":nome",$nome);

				$cadastrar=$inserir->execute($dados);

				//se cadastro do usuario der certo
				if($cadastrar){
					$result=1;
				}else{
					//erro no cadastro do usuario
					$result=0;
					//deleta a loja
					$QuerydeletarLoja=$pdo->prepare("DELETE FROM loja WHERE cnpjLoja='".$cnpj."'");
					$dadosLoja= array($cnpj);
					$deletarLoja=$QuerydeletarLoja->execute($dadosLoja);

				}
				
			}else{
				$result=4;
				//deleta a loja
				$QuerydeletarLoja=$pdo->prepare("DELETE FROM loja WHERE cnpjLoja='".$cnpj."'");
				$dadosLoja= array($cnpj);
				$deletarLoja=$QuerydeletarLoja->execute($dadosLoja);
			}
			
		}else{
			//erro no cadastro da loja
			$result=2;

		}
	}else{
		//loja ja cadastrada
		$result=3;

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
			if (resultado==1) {
				alert("Cadastro realizado com sucesso!");
				window.location.href="login.html";
			}
			if (resultado==2) {
				alert("Erro ao cadastrar loja!");
				window.location.href="login.html";
			}
			if (resultado==3) {
				alert("Loja já cadastrada!");
				window.location.href="login.html";
			}
			if (resultado==4) {
				alert("Usuário já cadastrado!");
				window.location.href="login.html";
			}
		}
	</script>
</head>
<body onload="teste()">

</body>
</html>