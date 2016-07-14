<?php 
  require_once "conexao.php";
	
//$cnpj="123456";
//$email="marcos@hotmail.com";
  $placa="rt54";
 $buscaImagem=$pdo->prepare("SELECT * FROM imagem WHERE placaDoVeiculo='$placa'" );
 $buscaImagem->execute();
 $linha=$buscaImagem->fetchAll(PDO::FETCH_OBJ);
	// se usuario nao estive cadastrado
	//var_dump($linha);
 // echo "qnt " .$buscaImagem->rowcount();


?>
<div class="container-fluid">
  <br>

  <div id="myCarousel" class="carousel slide col-md-5" data-ride="carousel">
    <!-- Indicators -->

    <ol class="carousel-indicators">
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
          <h3>Chania</h3>
          <p>The atmosphere in Chania has a touch of Florence and Venice.</p>
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