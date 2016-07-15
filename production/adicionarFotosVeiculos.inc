<?php 
 require_once "conexao.php";
 $placa=$_GET['placa'];
 
  $buscaImagem=$pdo->prepare("SELECT * FROM imagem WHERE placaDoVeiculo='$placa'" );
    
    $buscaImagem->execute();
    $linha=$buscaImagem->fetchAll(PDO::FETCH_OBJ);
    
?>

<div class="container-fluid">
  <div class=" col-md-12">
    <div class="row">
      <h3>Cadastar ou Remover imagem do veiculo de placa <?php echo $placa ;?> </h3>
      <div class="col-md-4">
        <form action="cadastrarImagemVeiculo.php" method="post" enctype="multipart/form-data"
        onsubmit="comprova_extensao(this.form, this.form.imagem.value);return false;">

          <div class="form-group col-md-4">
          <img alt="Bootstrap Image Preview" src="images/simboloImg.png" class="img-thumbnail" />
            <label for="exampleInputFile">Imagem</label>
            <input type="file" name="imagem" required="" />
              <p class="help-block">Escolha uma imagem para o veículo.</p>
            <input type="text" hidden="" name="placa" value="<?php echo $placa; ?>">
            <button type="submit" class="btn btn-success" onclick="">
              Cadastrar
           </button>
          </div>
        </form>
      </div>
      <!--form carregar imagem cadastradas-->
      <?php  
        if ($buscaImagem->rowcount()>0) { 
           foreach($linha as $listar ){            
        ?>
          <div class="col-md-2">
            <img alt="Bootstrap Image Preview" class="img-thumbnail" src=<?php echo $listar->imagem; ?>  />
            <form action="deletarImagem.php" method="post" onsubmit="deletarImagem(this);return false;">
              <input type="text" hidden="" name="idImagem" value="<?php echo $listar->idImagem ?>">
              <input type="text" hidden="" name="imagem" value="<?php echo $listar->imagem ?>">
              <button type="submit" class="btn btn-danger" ><span class="glyphicon glyphicon-trash"></span> 
              Deletar</button>
            </form>
          </div>
        <?php 
            }
          }
        ?>


      <!--fim form carregar imagem cadastradas-->
    </div>
  </div>
</div>  

<script type="text/javascript">

function deletarImagem(frm){
  var resp=confirm("Deseja excluir essa imagem?");

  if (resp) {
    frm.submit();
   return true;
  }else{
  return false;
   
  }
 }


  function comprova_extensao(formulario, arquivo) { 
    alert("ola");
    alert(arquivo);
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
         //alert ("Tudo correto. Vou submeter o formulário."); 
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
