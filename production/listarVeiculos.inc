<?php 
 require_once "conexao.php";
 	$buscaVeiculo=$pdo->prepare("SELECT * FROM veiculo " );
  	
  	$buscaVeiculo->execute();
  	$linha=$buscaVeiculo->fetchAll(PDO::FETCH_OBJ);

	 $placa="rt54";
	 $buscaImagem=$pdo->prepare("SELECT * FROM imagem WHERE placaDoVeiculo='$placa'" );
	 $buscaImagem->execute();
	 $linhaImg=$buscaImagem->fetchAll(PDO::FETCH_OBJ);
  	
?>

<div class="container-fluid">
	<div class="row">
		<div class="col-md-12">
			<div class="row">
			<?php 
			if ($buscaVeiculo->rowcount()>0) {
			 foreach($linha as $listar ){ 
				
			 ?>

				<div class="col-md-4">
					<div class="panel panel-success">
						<div class="panel-heading">
							<h3 class="panel-title">
								<?php echo $listar->nome."/ Ano ".$listar->ano."/ Modelo ".$listar->modelo; ?>
							</h3>
						</div>
						<div class="panel-body">
							<img class="col-md-12" alt="Bootstrap Image Preview"  class="img-thumbnail"                 src=<?php //echo $listar->imagem;?> />
						</div>
						<div class="panel-footer">
						<a href=<?php echo "index.php?id=detalheVeiculo&placa=".$listar->placa;?>
						  
						><font size="3">	Detalhe >> </font> </a>
						</div>
					</div>
				</div>
				
				<?php  } 
					}else{
          			echo "<h2>Não á veículo cadastrado</h2>";
          			}
          		?>

			</div>
		</div>
	</div>
</div>