<?php 
	require_once "conexao.php";
	$idImagem=$_POST['idImagem'];
	$imagem=$_POST['imagem'];
  $placa=$_POST['placa'];

    $buscaImagem=$pdo->prepare("SELECT * FROM imagem WHERE idImagem='$idImagem' and principal=1");
    $buscaImagem->execute();
    $linha=$buscaImagem->fetchAll(PDO::FETCH_OBJ); 
    if ($buscaImagem->rowcount()==0) {

      $deletarImagem=$pdo->prepare("DELETE FROM imagem WHERE idImagem= :idImagem");
      $deletarImagem->bindParam(':idImagem', $idImagem); 
      $deletarImagem->execute();
    }else{

      $deletarImagem=$pdo->prepare("DELETE FROM imagem WHERE idImagem= :idImagem");
      $deletarImagem->bindParam(':idImagem', $idImagem); 
      $deletarImagem->execute();
      $buscaImagem=$pdo->prepare("SELECT * FROM imagem WHERE placaDoVeiculo='$placa'");
      $buscaImagem->execute();
      $linha=$buscaImagem->fetchAll(PDO::FETCH_OBJ); 
      $i=0;
    
      echo "</br>linhas ".$buscaImagem->rowcount();
      if ($buscaImagem->rowcount()>0) {
    
        foreach ($linha as $listar) {
          if ($i==0) {
          
              $stmt = $pdo->prepare('UPDATE imagem SET principal = :principal WHERE idImagem = :idImagem');

              $stmt->execute(array( ':idImagem'  => $listar->idImagem,':principal' => 1));
            
          }
          if ($i>0) {
           break;  
         }

          $i++;
        }
      }
    
    }


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
        //window.location.href="index.php?id=cadastrarImagemVeiculo&nome=nomeVeiculo";
        
      }
      if (resultado==1) {
        alert("Imagem deletada com sucesso!");
        //history.back(1);
      }
    }
  </script>
</head>
<body onload="teste()">

</body>
</html>