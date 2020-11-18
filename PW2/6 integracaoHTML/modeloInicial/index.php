<?php
	include("util.php");
	$starWarsArray = json_decode($personagensSW,true);	
	debug($starWarsArray[0]['name']);	
	debug($starWarsArray[0]);	
	//debug($starWarsArray);	
?>

<!DOCTYPE html>
<html lang="pt-br">
<head>
	<meta charset="UTF-8">
	<!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
	<title>INTEGRAÇÃO PHP</title>
	<link rel="stylesheet" type="text/css" href="css/estilo.css">
</head>
<body>
	<div class="container">
		<header id="cabecalho">
			<h1>INTEGRAÇÃO PHP COM HTML</h1>
			<nav id="menu">
				<ul>
					<a href="index.php"><li>INTEGRAÇÃO PHP</li></a>
					<a href="#"><li>Página 2</li></a>
					<a href="#"><li>Página 3</li></a>
				</ul>
			</nav>
		</header>
		<section id="principal">
			<div id="calculadora" class="contorno">
				<header>
					<h2></h2>
				</header>
				<h1>Montar uma tabela aqui com os dados dos personagens</h1>
				<br style="clear: both">		
			</div>
		</section>
		<footer>
			Sistema desenvolvido por Rodrigo Henrique Ramos - 2020B
		</footer>
	</div>
</body>
</html>

<!-- JS Libs-->
<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>