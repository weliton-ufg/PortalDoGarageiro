<?php

  require_once "conexao.php";

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
         $placa=$_POST['placa'];



        $buscaImagem=$pdo->prepare("SELECT * FROM imagem WHERE placaDoVeiculo='$placa'" );
        $buscaImagem->execute();
        $linha=$buscaImagem->fetchAll(PDO::FETCH_OBJ); 
        if ($buscaImagem->rowcount()==0) {
          $principal=1;
        }else{
          $principal=0;
        }

           
          $inserirImagem=$pdo->prepare("INSERT INTO imagem(placaDoVeiculo,imagem,principal)VALUES(?,?,?)");
          $dadosImagem= array($placa,$destino,$principal);
          $cadastrarImagem=$inserirImagem->execute($dadosImagem);
          if ($cadastrarImagem) {
            $result=1;
          }else{
             $result=0;
             ;
          }

          move_uploaded_file( $arquivo_tmp, $destino  );    
      }
    }
  ?>
  <html>
<head>
  <title></title>
  <script type="text/javascript">
    function teste(){
      var resultado = "<?php echo $result; ?>";
     
      var placa = "<?php echo $placa; ?>";
      if (resultado==0) {
        alert("Erro ao cadastrar imagem!");
        //window.location.href="index.php?id=cadastrarVeiculo";
        history.back(1);
        //avascript:history.go(1);
      }
      if (resultado==1) {
        alert("Imagem Cadastrada com sucesso!");
        history.back(1);

      }
    }
  </script>
</head>
<body onload="teste()">

</body>
</html>