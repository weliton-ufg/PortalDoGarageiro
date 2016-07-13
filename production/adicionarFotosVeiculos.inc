<?php
  if ( isset( $_FILES[ 'imagem' ][ 'name' ] ) && $_FILES[ 'imagem' ][ 'error' ] == 0 ) {
      $arquivo_tmp = $_FILES[ 'imagem' ][ 'tmp_name' ];
      $nome = $_FILES[ 'imagem' ][ 'name' ];
   
      // Pega a extensão
      $extensao = pathinfo ( $nome, PATHINFO_EXTENSION );
   
      // Converte a extensão para minúsculo
      $extensao = strtolower ( $extensao );
   
      // Somente imagens, .jpg;.jpeg;.gif;.png
      // Aqui eu enfileiro as extensões permitidas e separo por ';'
      // Isso serve apenas para eu poder pesquisar dentro desta String
      if ( strstr ( '.jpg;.jpeg;.gif;.png', $extensao ) ) {
          // Cria um nome único para esta imagem
          // Evita que duplique as imagens no servidor.
          // Evita nomes com acentos, espaços e caracteres não alfanuméricos
          $novoNome = uniqid ( time () ) .".". $extensao;
         // echo $novoNome;
   
          // Concatena a pasta com o nome
          $destino = 'imagens_Veiculos/'. $novoNome;
          move_uploaded_file( $arquivo_tmp, $destino  );
          echo $_GET['placa'];
          

      }
  }
  ?>


<script type="text/javascript">
	function comprova_extensao(formulario, arquivo) { 
   extensoes_permitidas = new Array(".gif", ".jpg", ".png", ".jpeg");
   msg = ""; 
 
   if (!arquivo) { 
      //Se não tenho arquivo, é porque não se selecionou um arquivo no formulário. 
        msg = "Não foi selecionado nenhum arquivo"; 
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
        }else{ 
          //submeto! 
         alert ("Tudo correto. Vou submeter o formulário."); 
         formulario.submit(); 
         return 1; 
        } 
   } 
   //se estou aqui é porque não se pode submeter 
   alert (msg); 
   return 0; 
} 
</script>


<div class="container-fluid">
  <div class=" col-md-12">
    <div class="row">

      <div class="col-md-5">
        <form>

          <div class="form-group col-md-5">
            <label for="exampleInputFile">Imagem</label>
            <input type="file" name="imagem" />
              <p class="help-block">Escolha uma imagem para o veículo.</p>

            <button  class="btn btn-primary" onclick="comprova_extensao(this.form, this.form.imagem.value)">
              Cadastrar
           </button></a>
          </div>
        </form>
      </div>
      <!--form carregar imagem cadastradas-->
          <div class="col-md-3">
            <img alt="Bootstrap Image Preview" src="imagens_Veiculos/146835808757855dc73d124.jpg" class="img-thumbnail" />
          </div>
          <div class="col-md-3">
            <img alt="Bootstrap Image Preview" src="imagens_Veiculos/146835808757855dc73d124.jpg" class="img-thumbnail" />
          </div>

      <!--fim form carregar imagem cadastradas-->
    </div>
  </div>
</div>       