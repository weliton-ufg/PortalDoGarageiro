<?php 
 require_once "conexao.php";
 $id=$_POST['idUsuario'];



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
         $foto = 'fotosUsuarios/'. $novoNome;
        

          $stmt = $pdo->prepare('UPDATE pessoa SET foto = :foto WHERE id = :id');
          $stmt->execute(array( ':id' => $id,':foto' => $foto));
          
          if ($stmt) {
            $result=1;
            echo "deu certo";
          }else{
             echo "deu errado";
          }

        }
 
    }





 ?>