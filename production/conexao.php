<?php	
	//conectando com o banco	
	try{
		$pdo= new PDO("mysql:host=localhost;dbname=teste","root","vertrigo");
		
	}catch(PDOException $e){
		echo $e->getMessage;

	}
?>