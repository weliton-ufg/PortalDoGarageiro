<?php 

  require_once "conexao.php";
	
$cnpj="123456";
$email="marcos@hotmail.com";
	$buscaUsuario=$pdo->prepare("SELECT * FROM pessoa WHERE email='$email' AND cnpj='$cnpj'" );
	$buscaUsuario->execute();
	$linha=$buscaUsuario->fetchAll(PDO::FETCH_OBJ);
	// se usuario nao estive cadastrado
	var_dump($linha);
	if ($buscaUsuario->rowcount()>0) {	

		echo "Ja existe";
	}
?>