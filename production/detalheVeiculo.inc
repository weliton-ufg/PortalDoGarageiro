<?php
	require_once "conexao.php";
	$placa=$_GET['placa'];

	$buscaVeiculo=$pdo->prepare("SELECT * FROM veiculo WHERE  placa='$placa'" );
	$buscaVeiculo->execute();
	$linha=$buscaVeiculo->fetchAll(PDO::FETCH_OBJ);

	if ($buscaVeiculo->rowcount()>0) {
			 foreach($linha as $listar ){ 

			 $nome=$listar->nome;
			 $placa=$listar->placa;
			 $ano=$listar->ano;
			 $modelo=$listar->modelo;
			 $renavan=$listar->renavan;
			 $chassi=$listar->chassi;
			 $cor=$listar->cor;
			 $categoria=$listar->categoria;
			 $descricao=$listar->descricao;
			 $marca=$listar->marca;
			 $valorCompra=$listar->valorCompra;
			 $valorVenda=$listar->valorVenda;
			 $combustivel=$listar->combustivel;
			 $observacao=$listar->observacao;
			 $dataAquisicao=$listar->dataAquisicao;

		}
	}
 //$placa="rt54";
 $buscaImagem=$pdo->prepare("SELECT * FROM imagem WHERE placaDoVeiculo='$placa'" );
 $buscaImagem->execute();
 $linha=$buscaImagem->fetchAll(PDO::FETCH_OBJ);		

?>
<div class="container-fluid col-md-12">
	<div class="row">
		<!--inicio carrossel -->
   <div class="container-fluid">
  <br>

  <div id="myCarousel" class="carousel slide col-md-4" data-ride="carousel">
    <!-- Indicators -->

    <ol class="carousel-indicators">
      <?php 
     	$j=0;
  		if ($buscaImagem->rowcount()>0) {
  			foreach ($linha as $listar) {
  				$j++;			    
      ?>
      <li data-target="#myCarousel" 
      class="<?php if($j==1 ){echo "active";}else{echo "";} ?>"      
      data-slide-to="<?php echo $j ; ?>"> </li>
    <!--  <li data-target="#myCarousel" data-slide-to="1"></li> -->
     <?php }} ?>
    </ol>
   
    <!-- Wrapper for slides -->
    <div class="carousel-inner" role="listbox">
    <?php 
     	$i=0;
  		if ($buscaImagem->rowcount()>0) {
  			foreach ($linha as $listar) {
  				$i++;			    
   ?>

      <div class="<?php  if($i==1){ echo "item active";}else{ echo "item"; } ?>" >
        <img src="<?php echo $listar->imagem; ?>" alt="Chania" width="460" height="345">
        <div class="carousel-caption">
          <h3>Portal do Garageiro</h3>
          <p>Sua melhor escolha.</p>
        </div>
      </div>

<?php }} ?>
    <!-- Left and right controls -->
    <a class="left carousel-control" href="#myCarousel" role="button" data-slide="prev">
      <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
      <span class="sr-only">Previous</span>
    </a>
    <a class="right carousel-control" href="#myCarousel" role="button" data-slide="next">
      <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
      <span class="sr-only">Next</span>
    </a>
  </div>
</div>
		<!-- fim carrossel-->

	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">nome</label>
		<input type="" class="form-control" name="observacao" value=<?php echo $nome ;?> />
	    </div>

	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">Marca</label>
		<input type="" class="form-control" name="observacao" value=<?php echo $marca ;?> />
	    </div>

	    <div class="form-group col-md-1"> 
		<label for="exampleInputEmail1">Ano</label>
		<input type="" class="form-control" name="observacao" value=<?php echo $ano ;?> />
	    </div>

	    <div class="form-group col-md-1"> 
		<label for="exampleInputEmail1">Modelo</label>
		<input type="" class="form-control" name="observacao" value=<?php echo $modelo ;?> />
	    </div>

	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">Cor</label>
		<input type="" class="form-control" name="observacao" value=<?php echo $cor ;?> />
	    </div>

	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">Placa</label>
		<input type="text" class="form-control" name="observacao" value=<?php echo $placa ;?> />
	    </div>

	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">Chassi</label>
		<input type="text" class="form-control" name="observacao" value=<?php echo $chassi ;?> />
	    </div>

	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">Renavan</label>
		<input type="text" class="form-control" name="observacao" value=<?php echo $renavan ;?> />
	    </div>

	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">Valor de compra</label>
		<input type="text" class="form-control" name="observacao" value=<?php echo $valorCompra ;?> />
	    </div>

	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">Valor de vendar</label>
		<input type="text" class="form-control" name="observacao" value=<?php echo $valorVenda ;?> />
	    </div>

	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">Combustivel</label>
		<input type="text" class="form-control" name="observacao" value=<?php echo $combustivel ;?> />
	    </div>

	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">Data de aquisição</label>
		<input type="date" class="form-control" name="observacao" value=<?php echo $dataAquisicao ;?> />
	    </div>


	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">Categoria</label>
		<input type="text" class="form-control" name="observacao" value=<?php echo $categoria ;?> />
	    </div>

	    <div class="form-group col-md-4"> 
		<label for="exampleInputEmail1">Observação</label>
		<input type="text" class="form-control" name="observacao" value=<?php echo $observacao ;?> />
	    </div>

	    <div class="form-group col-md-4"> 
		<label for="exampleInputEmail1">Descrição</label>
		<input type="text" class="form-control" name="observacao" value=<?php echo $descricao ;?> />
	    </div>
		
	    <div class="form-group col-md-4">
	    </br>
	    	<button  class="btn btn-primary " onclick="window.location.href='index.php?id=listarVeiculos';" )">
			<span class="glyphicon glyphicon-arrow-left" aria-hidden="true"></span>
	    	 Voltar</button></a>
	    	<button  class="btn btn-warning " )"> 
			<span class="glyphicon glyphicon glyphicon-pencil" aria-hidden="true"></span>
	    	Editar</button></a>
	        <button type="" class="btn btn-danger ">
			<span class="glyphicon glyphicon-trash" aria-hidden="true"></span>
	         Excluir</button>
		</div>
	</div>
</div>


