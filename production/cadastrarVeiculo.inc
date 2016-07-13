<script type="text/javascript">
	function comprova_extensao(formulario, arquivo1,arquivo2,arquivo3,arquivo4) { 
   extensoes_permitidas = new Array(".gif", ".jpg", ".png", ".jpeg");
   meuerro = ""; 
   alert(arquivo1);
   if (!arquivo1 && !arquivo2 && !arquivo3 !arquivo4) { 
      //Se não tenho arquivo, é porque não se selecionou um arquivo no formulário. 
        meuerro = "Não foi selecionado nenhum arquivo"; 
   }else{ 
      //recupero a extensão deste nome de arquivo 
      extensao = (arquivo1.substring(arquivo1.lastIndexOf("."))).toLowerCase(); 
      extensao2 = (arquivo2.substring(arquivo2.lastIndexOf("."))).toLowerCase(); 
      extensao3 = (arquivo3.substring(arquivo3.lastIndexOf("."))).toLowerCase(); 
      extensao4 = (arquivo4.substring(arquivo4.lastIndexOf("."))).toLowerCase(); 
      //alert (extensao); 
      //comprovo se a extensão está entre as permitidas 
      permitida = false; 
      for (var i = 0; i < extensoes_permitidas.length; i++) { 
         if (extensoes_permitidas[i] == extensao && extensoes_permitidas[i] == extensao2  
         	 && extensoes_permitidas[i] == extensao3 && extensoes_permitidas[i] == extensao ) { 
         permitida = true; 
         break; 
         } 
      } 
      if (!permitida) { 
         meuerro = "Ocorreu um erro. \nSó se podem subir arquivos com extensões: " + extensoes_permitidas.join(); 
        }else{ 
          //submeto! 
         alert ("Tudo correto. Vou submeter o formulário."); 
         formulario.submit(); 
         return 1; 
        } 
   } 
   //se estou aqui é porque não se pode submeter 
   alert (meuerro); 
   return 0; 
} 
</script>

<div class=" col-xs-12">

<form role="form" method="post" action="cadastrarVeiculo.php" enctype="multipart/form-data">

	<div class="form-group col-md-4">
		<label for="sel1">Marca</label> 
		<select name="marca"
			class="form-control">
			<option value="Fiat">Fiat</option>
			<option value="BMW">BMW</option>
		</select>
	</div>
	<div class="form-group col-md-4">
		<label for="sel1">Categoria</label> 
		<select name="categoria"
			class="form-control">
			<option value="Básico">Básico</option>
			<option value="Completo">Completo</option>
		</select>
	</div>
	<div class="form-group col-md-4">
		 
		<label for="exampleInputEmail1">Nome</label>
		<input type="" class="form-control" name="nome" required="" />
	</div>
		<div class="form-group col-md-8">
		 
		<label for="exampleInputEmail1">Descrição</label>
		<input type="" class="form-control" name="descricao" />
	</div>
		<div class="form-group col-md-1">
		 
		<label for="exampleInputEmail1">Ano</label>
		<input type="" class="form-control" name="ano" required=""/>
	</div>

	<div class="form-group col-md-1">
		 
		<label for="exampleInputEmail1">Modelo</label>
		<input type="" class="form-control" name="modelo" required=""/>
	</div>

		<div class="form-group col-md-2">
		 
		<label for="exampleInputEmail1">Cor</label>
		<input type="" class="form-control" name="cor" />
	</div>
		<div class="form-group col-md-3">
		 
		<label for="exampleInputEmail1">Placa</label>
		<input type="" class="form-control" name="placa" required=""/>
	</div>
	<div class="form-group col-md-3"> 
		<label for="exampleInputEmail1">Chassi</label>
		<input type="" class="form-control" name="chassi" required=""/>
	</div>
	<div class="form-group col-md-2">
		 
		<label for="exampleInputEmail1">Renavan</label>
		<input type="" class="form-control" name="renavan" required=""/>
	</div>
		<div class="form-group col-md-2">
		 
		<label for="exampleInputEmail1">Valor de compra</label>
		<input type="number" class="form-control" name="valorCompra" required=""/>
	</div>
		<div class="form-group col-md-2">
		 
		<label for="exampleInputEmail1">Valor de venda</label>
		<input type="number" class="form-control" name="valorVenda" required=""/>
	</div>



		
	<div class="form-group col-md-3">
		<label for="sel1">Combustivel</label> 
		<select name="combustivel"
			class="form-control">
			<option value="Gasolina">Gasolina</option>
			<option value="Alcool">Álcool</option>
			<option value="Diesel">Diesel</option>
			<option value="Flex">Flex</option>
		</select>
	</div>
	<div class="form-group col-md-3"> 
		<label for="exampleInputEmail1">Data de aquisição</label>
		<input type="date" class="form-control" name="dataAquisicao" />
	</div>
	<div class="form-group col-md-3">
		<label for="sel1">Câmbio</label> 
		<select name="cambio"
			class="form-control">
			<option value="Manual">Manual</option>
			<option value="Altomático">Altomático</option>
		</select>
	</div>
	<div class="form-group col-md-3"> 
		<label for="exampleInputEmail1">Kilometragem</label>
		<input type="text" class="form-control" name="kilometragem" />
	</div>
	<div class="form-group col-md-6">
		 
		<label for="exampleInputEmail1">Observação</label>
		<input type="" class="form-control" name="observacao" />
	</div>

	</div>

	<div class="form-group col-md-4">
	&nbsp;&nbsp;&nbsp;<button  class="btn btn-primary" )">
		cadastrar
	</button></a>
	<button type="" class="btn btn-warning ">
		Limpar
	</button>
	</div>
</form>
</div>
