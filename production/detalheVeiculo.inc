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
<div class="container-fluid col-md-12" >
	<div class="row">
		<!--inicio carrossel -->
   <div class="container-fluid">
  <br>

  <div id="myCarousel" class="carousel slide col-md-4" data-ride="carousel">
    <!-- Indicators -->

    <ol class="carousel-indicators">

  <?php if ($buscaImagem->rowcount()==0) { ?>
    <li data-target="#myCarousel" class="active" data-slide-to="0"> </li>
    </ol>
   
    <!-- Wrapper for slides -->
    <div class="carousel-inner" role="listbox">
      <div class="item active">
        <img src="images/semImagemCadastrada.jpg" alt="Chania" width="460" height="345">
        <div class="carousel-caption">
          <h3></h3>
          <p></p>
        </div>
      </div>
     </div>

     <?php }?>


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
		<input type="" class="form-control" id="nome" name="nome" disabled value=<?php echo $nome ;?> />
	    </div>

	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">Marca</label>
		<input type="" class="form-control" id="marca" name="marca" disabled value=<?php echo $marca ;?> />
	    </div>

	    <div class="form-group col-md-1"> 
		<label for="exampleInputEmail1">Ano</label>
		<input type="" class="form-control" id="ano" name="ano" disabled value=<?php echo $ano ;?> />
	    </div>

	    <div class="form-group col-md-1"> 
		<label for="exampleInputEmail1">Modelo</label>
		<input type="" class="form-control" id="modelo" name="modelo" disabled value=<?php echo $modelo ;?> />
	    </div>

	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">Cor</label>
		<input type="" class="form-control" id="cor" name="cor" disabled value=<?php echo $cor ;?> />
	    </div>

	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">Placa</label>
		<input type="text" class="form-control" id="placa" name="placa" disabled value=<?php echo $placa ;?> />
	    </div>

	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">Chassi</label>
		<input type="text" class="form-control" id="chassi" name="chassi" disabled value=<?php echo $chassi ;?> />
	    </div>

	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">Renavan</label>
		<input type="text" class="form-control" id="renavan" name="renavam" disabled value=<?php echo $renavan ;?> />
	    </div>

	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">Valor de compra</label>
		<input type="text" class="form-control" id="valorCompra" name="vaLorCompar" disabled value=<?php echo $valorCompra ;?> />
	    </div>

	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">Valor de vendar</label>
		<input type="text" class="form-control" id="valorVenda" name="valorVenda" disabled value=<?php echo $valorVenda ;?> />
	    </div>


	    <div class="form-group col-md-2" >
		<label for="sel1">Combustivel</label> 
			<select name="combustivel" id="combustivel" disabled " 
				class="form-control"  >
				<option value=""></option>
				<option value="Alcool">Álcool</option>
				<option value="Gasolina">Gasolina</option>
				<option value="Diesel">Diesel</option>
				<option value="Flex">Flex</option>
			</select>
	    </div>

	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">Data de aquisição</label>
		<input type="date" class="form-control" id="dataAquisicao" name="dataaquisicao" disabled value=<?php echo $dataAquisicao ;?> />
	    </div>


	    <div class="form-group col-md-2"> 
		<label for="exampleInputEmail1">Categoria</label>
		<input type="text" class="form-control" id="categoria" name="categoria" disabled value=<?php echo $categoria ;?> />
	    </div>

		<div class="form-group col-md-2">
			<label for="sel1">Câmbio</label> 
			<select name="cambio" id="cambio" disabled 
				class="form-control">
				<option value="Manual"></option>
				<option value="Manual">Manual</option>
				<option value="Altomático">Altomático</option>
				<option value="Altomático">Automatizado</option>
				<option value="Altomático">CVT</option>
			</select>
		</div>

	    <div class="form-group col-md-3"> 
		<label for="exampleInputEmail1">Observação</label>
		<textarea type="text" class="form-control" id="observacao" name="observacao" disabled ><?php echo $observacao ;?>
		</textarea>
	    </div>

	    <div class="form-group col-md-3"> 
		<label for="exampleInputEmail1">Descrição</label>
		<textarea class="form-control" id="descricao" name="descricao" disabled  ><?php echo $descricao ;?>
		</textarea>

	    </div>
		
	    <div class="form-group col-md-4">
	    </br>
	    	<button  class="btn btn-primary " onclick="window.location.href='index.php?id=listarVeiculos';" )">
			<span class="glyphicon glyphicon-arrow-left" aria-hidden="true"></span>
	    	 Voltar</button>
	    	<button  class="btn btn-warning" onclick="editar()" id="btnEditar"> 
			<span class="glyphicon glyphicon-pencil" id="icone" aria-hidden="true"></span>
	    	<span id="textoBtn">Editar</span></button>
	        <button type="" class="btn btn-danger ">
			<span class="glyphicon glyphicon-trash" aria-hidden="true"></span>
	        Excluir</button>
	        <button type="" class="btn btn-danger "onclick="window.location.href='index.php?id=adicionarFotosVeiculos&placa=<?php echo $placa; ?>&nome=<?php echo $nome; ?>';" )" ">
	        <span class="glyphicon glyphicon-plus" aria-hidden="true"></span>
	        <span class="glyphicon glyphicon-picture" aria-hidden="true"></span>
	        <span id="textoBtn">imagem</span>
			<span class="glyphicon glyphicon-trash" aria-hidden="true"></span>
	        </button>
		</div>
	
	</div>
</div>

<script type="text/javascript">
   function selects(){
   	//alert("ola");
    var combustivel="<?php echo $combustivel ;?>";
    if (combustivel=="Alcool") {
 		document.getElementById('combustivel').selectedIndex=1;
 	}
 	if (combustivel=="Gasolina") {
 		document.getElementById('combustivel').selectedIndex=2;
 	}
 	if (combustivel=="Diesel") {
 		document.getElementById('combustivel').selectedIndex=3;
 	}
 	if (combustivel=="Flex") {
 		document.getElementById('combustivel').selectedIndex=4;
 	}
   //document.getElementById('combustivel').selectedIndex=2;
   	//comboCidades.selectedIndex = 2;
   } 
	
	function editar(){
		if(document.getElementById('descricao').disabled){
			document.getElementById('nome').disabled=false;
			document.getElementById('marca').disabled=false;
			document.getElementById('ano').disabled=false;
			document.getElementById('modelo').disabled=false;
			document.getElementById('cor').disabled=false;
			document.getElementById('placa').disabled=false;
			document.getElementById('chassi').disabled=false;
			document.getElementById('renavan').disabled=false;
			document.getElementById('valorCompra').disabled=false;
			document.getElementById('valorVenda').disabled=false;
			document.getElementById('combustivel').disabled=false;
			document.getElementById('dataAquisicao').disabled=false;
			document.getElementById('observacao').disabled=false;
			document.getElementById('descricao').disabled=false;
			document.getElementById('cambio').disabled=false;
			document.getElementById('categoria').disabled=false;
			//document.getElementById('btnEditar').text="Salvar";
			document.getElementById("textoBtn").innerHTML=" Salvar";
			document.getElementById('btnEditar').className="btn btn-success";
			document.getElementById('icone').className="glyphicon glyphicon-floppy-disk";
		}else{
			document.getElementById('nome').disabled=true;
			document.getElementById('marca').disabled=true;
			document.getElementById('ano').disabled=true;
			document.getElementById('modelo').disabled=true;
			document.getElementById('cor').disabled=true;
			document.getElementById('placa').disabled=true;
			document.getElementById('chassi').disabled=true;
			document.getElementById('renavan').disabled=true;
			document.getElementById('valorCompra').disabled=true;
			document.getElementById('valorVenda').disabled=true;
			document.getElementById('combustivel').disabled=true;
			document.getElementById('dataAquisicao').disabled=true;
			document.getElementById('observacao').disabled=true;
			document.getElementById('descricao').disabled=true;
			document.getElementById('cambio').disabled=true;
			document.getElementById('categoria').disabled=true;
			document.getElementById("textoBtn").innerHTML="Editar";
			document.getElementById('btnEditar').className="btn btn-warning";
			document.getElementById('icone').className="glyphicon glyphicon-pencil";
		}
		
	}
</script>
