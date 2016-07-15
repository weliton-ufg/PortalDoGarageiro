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
	$cnpjLoja="123456";
	$cambio=$_POST['cambio'];
	$kilometragem=$_POST['kilometragem'];
	$buscaVeiculo=$pdo->prepare("SELECT * FROM veiculo WHERE placa ='$placa'" );

  	$buscaVeiculo->execute();
  	$linha=$buscaVeiculo->fetchAll(PDO::FETCH_OBJ);

	if ($buscaVeiculo->rowcount()==0) {
		$inserir=$pdo->prepare("INSERT INTO veiculo(marca,categoria,nome,descricao,ano,modelo,cor,placa,chassi,	renavan,valorCompra,valorVenda,combustivel,dataAquisicao,observacao,cnpjLoja,cambio,kilometragem
)VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
		
		$dados =array($marca,$categoria,$nomeVeiculo,$descricao,$ano,$modelo,$cor,$placa,$chassi,$renavan,$valorCompra,$valorVenda,$combustivel,$dataAquisicao,$observacao,$cnpjLoja,$cambio,$kilometragem);
		
		//var_dump($inserir);
		//var_dump($dados);
		$cadastrar=$inserir->execute($dados);
		//var_dump($cadastrar);
		
		if ($cadastrar) {
			$result=1;
			//echo "Cadastro realizado com sucesso!";
			//header("Location:index.php?id=adicionarFotosVeiculos");		
		}
		
	}else{
		//echo "Veiculo jacastrado!";
		$result=0;

	}
//
?>

<html>
<head>
	<title></title>
	<script type="text/javascript">
		function teste(){
			var resultado = "<?php echo $result; ?>";
			var placa = "<?php echo $placa; ?>";
			if (resultado==0) {
				alert("Esta Placa já está castrada para outro veículo!");
	 			//window.location.href="index.php?id=cadastrarVeiculo";
	 			history.back(1);
	 			//avascript:history.go(1);
			}
			if (resultado==1) {
				alert("Cadastro realizado com sucesso! ");
				window.location.href="index.php?id=adicionarFotosVeiculos&placa="+placa;

			}
		}
	</script>
</head>
<body onload="teste()">

</body>
</html>