<?php 
  require_once "conexao.php";
	
//$cnpj="123456";
//$email="marcos@hotmail.com";
 $placa="rt54";
 $buscaImagem=$pdo->prepare("SELECT *FROM veiculo JOIN imagem WHERE veiculo.placa=imagem.placaDoVeiculo" );
 $buscaImagem->execute();
 $linha=$buscaImagem->fetchAll(PDO::FETCH_OBJ);
	// se usuario nao estive cadastrado
	var_dump($linha);
 // echo "qnt " .$buscaImagem->rowcount();


?>