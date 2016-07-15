<?php 
	require_once "conexao.php";

	$idImagem=$_POST['idImagem'];
	$imagem=$_POST['imagem'];
	$deletarImagem=$pdo->prepare("DELETE FROM imagem WHERE idImagem= :idImagem");
	$deletarImagem->bindParam(':idImagem', $idImagem); 
    $deletarImagem->execute();
	if($deletarImagem){
		$result=1;
		unlink($imagem);
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
        alert("Erro ao deletar imagem!");
        //window.location.href="index.php?id=cadastrarVeiculo";
        history.back(1);
        //avascript:history.go(1);
      }
      if (resultado==1) {
        alert("Imagem deletada com sucesso!");
        history.back(1);
      }
    }
  </script>
</head>
<body onload="teste()">

</body>
</html>