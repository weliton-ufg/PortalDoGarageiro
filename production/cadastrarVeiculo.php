<?php

	require_once "conexao.php";
   
	$marca= $_POST['marca'];
	$categoria= $_POST['categoria'];
	$nomeVeiculo= $_POST['nome'];
	$descricao= $_POST['descricao'];
	$ano= $_POST['ano'];
	$modelo= $_POST['modelo'];
	$cor= $_POST['cor'];
	$placa= $_POST['placa'];
	$chassi= $_POST['chassi'];
	$renavan= $_POST['renavan'];
	$valorCompra= $_POST['valorCompra'];
	$valorVenda= $_POST['valorVenda'];
	$combustivel= $_POST['combustivel'];
	$dataAquisicao= $_POST['dataAquisicao'];
	$observacao= $_POST['observacao'];

// verifica se foi enviado um arquivo
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
	        

	    }
	}
	$buscaVeiculo=$pdo->prepare("SELECT * FROM veiculo WHERE placa ='$placa' AND chassi='$chassi'" );
  	//$buscaUsuario->bindValue(":id",1,PDO::PARAM_INT);
  	$buscaVeiculo->execute();
  	$linha=$buscaVeiculo->fetchAll(PDO::FETCH_OBJ);
  	//echo $buscaUsuario->rowcount()."<br/>";

	if ($buscaVeiculo->rowcount()==0) {
		$inserir=$pdo->prepare("INSERT INTO veiculo(marca,categoria,nome,descricao,ano,modelo,cor,placa,chassi,renavan,valorCompra,valorVenda,combustivel,dataAquisicao,observacao,imagem)VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
		
		$dados =array($marca,$categoria,$nomeVeiculo,$descricao,$ano,$modelo,$cor,$placa,$chassi,$renavan,$valorCompra,$valorVenda,$combustivel,$dataAquisicao,$observacao,$destino);
		
		var_dump($inserir);
		var_dump($dados);
		$cadastrar=$inserir->execute($dados);
		

		var_dump($cadastrar);
		
		if ($cadastrar) {
			echo "Cadastro realizado com sucesso!";
			move_uploaded_file( $arquivo_tmp, $destino  );
		}
		
	}else{
		echo "Veiculo jacastrado!";
	}


//header("Location:index.php?id=cadastrarVeiculo");
?>