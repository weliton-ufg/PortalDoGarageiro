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

?>
<div class="container-fluid col-md-12">
	<div class="row">
		<div >
			<img class="col-md-4" alt="Bootstrap Image Preview"  class="img-thumbnail" 
			src=<?php echo $listar->imagem;?>  />
		</div>

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


