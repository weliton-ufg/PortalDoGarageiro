<?php 
 require_once "conexao.php";
 	$buscaVeiculo=$pdo->prepare("SELECT * FROM veiculo " );
  	
  	$buscaVeiculo->execute();
  	$linha=$buscaVeiculo->fetchAll(PDO::FETCH_OBJ);
  	
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
							<img alt="Bootstrap Image Preview" height="100" width="100" class="img-thumbnail"                 src=<?php echo $listar->imagem;?> />
							Panel content
						</div>
						<div class="panel-footer">
						<a href="">	Panel footer </a>
						</div>
					</div>
				</div>
				
				<?php  } }else{
          echo "<h2>Não á veículo cadastrado</h2>";
          }?>

			</div>
		</div>
	</div>
</div>