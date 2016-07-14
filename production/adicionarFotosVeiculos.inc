<script type="text/javascript">
	function comprova_extensao(formulario, arquivo) { 
   extensoes_permitidas = new Array(".gif", ".jpg", ".png", ".jpeg");
   msg = ""; 
 
   if (!arquivo) { 
      //Se não tenho arquivo, é porque não se selecionou um arquivo no formulário. 
         
        //return 1;
   }else{ 
      //recupero a extensão deste nome de arquivo 
      extensao = (arquivo.substring(arquivo.lastIndexOf("."))).toLowerCase(); 
 
      //alert (extensao); 
      //comprovo se a extensão está entre as permitidas 
      permitida = false; 
      for (var i = 0; i < extensoes_permitidas.length; i++) { 
         if (extensoes_permitidas[i] == extensao) { 
         permitida = true; 
         break; 
         } 
      } 
      if (!permitida) { 
         msg = "Ocorreu um erro. \nSó se podem subir arquivos com extensões: " + extensoes_permitidas.join(); 
         return 0;
        }else{ 
          //submeto! 
         alert ("Tudo correto. Vou submeter o formulário."); 
         formulario.submit(); 
         return 1; 
        } 
   } 
   //se estou aqui é porque não se pode submeter 
   if(! msg==""){
       alert (msg); 
   }
  
   return 0; 
} 
</script>


<div class="container-fluid">
  <div class=" col-md-12">
    <div class="row">

      <div class="col-md-4">
        <form action="cadastrarImagemVeiculo.php" method="post" enctype="multipart/form-data">

          <div class="form-group col-md-4">
          <img alt="Bootstrap Image Preview" src="images/simboloImg.png" class="img-thumbnail" />
            <label for="exampleInputFile">Imagem</label>
            <input type="file" name="imagem" required="" />
              <p class="help-block">Escolha uma imagem para o veículo.</p>
            <input type="text" hidden="" name="placa" value="<?php echo $_GET['placa']; ?>">
            <button  class="btn btn-success" onclick="comprova_extensao(this.form, this.form.imagem.value)">
              Cadastrar
           </button>
          </div>
        </form>
      </div>
      <!--form carregar imagem cadastradas-->
          <div class="col-md-2">
            <img alt="Bootstrap Image Preview" src="imagens_Veiculos/146835808757855dc73d124.jpg" class="img-thumbnail" />
          </div>

      <!--fim form carregar imagem cadastradas-->
    </div>
  </div>
</div>       