<?php
	include("util.php");
?>

<!DOCTYPE html>
<html lang="pt-br">
<head>
	<meta charset="UTF-8">
	<title>FORM PHP</title>
	<link rel="stylesheet" type="text/css" href="css/estilo.css">
</head>
<body>
	<div id="conteudo">
		<header id="cabecalho">
			<h1>FORM PHP</h1>
			<nav id="menu">
				<ul>
					<a href="index.php"><li>FORM PHP</li></a>
					<a href="#"><li>Página 2</li></a>
					<a href="#"><li>Página 3</li></a>
				</ul>
			</nav>
		</header>
		<?php
			if(isset($_GET["msg"])) {
				echo "<div id='erro'";
					echo "<ul>";
						$campos = explode(";", $_GET["msg"]);
						for($i=0;$i<count($campos) - 1;$i++) {
							echo "<li>{$campos[$i]}</li>";
						}
					echo "<ul>";
				echo "</div>";
			}else if(isset($_GET["sucesso"])){
				echo "<div id='sucesso'";
				echo "<h1>Cadastrado com sucesso!</h1>";
				echo "</div>";
			}
		?>
		<section id="principal">
			<div id="calculadora" class="contorno">
				<form action="recebeForm.php" method="POST">
					<div id="divFormEsq">
					    <label for="fname">Primeiro Nome</label>
							<input type="text" id="fname" name="firstname" placeholder="Primeiro nome">

							<label for="sobrenome">Sobrenome</label>
					    <input type="text" id="lname" name="lastname" placeholder="Sobrenome">
					    
					    <label for="country">País</label>
					    <select id="country" name="country">
					      <option value="NULL"></option>	
					      <option value="australia">Australia</option>
					      <option value="canada">Canada</option>
					      <option value="brasil">Brasil</option>
					      <option value="usa">USA</option>
					    </select>

							<label for="cursos">Cursos</label>
							<input type="checkbox" name="cursos[]" value="PHP">PHP</input>
							<input type="checkbox" name="cursos[]" value="HTML<">HTML</input>
							<input type="checkbox" name="cursos[]" value="CSS">CSS</input>
						</div>

						<div id="divFormDir">
							<label for="email">E-mail</label>
							<input type="text" id="email" name="email" placeholder="E-mail">	

							<label for="senha">Senha</label>
					    <input type="password" id="senha" name="senha" placeholder="Senha">

							<label for="telefone">Telefone</label>
					    <input type="text" id="telefone" name="telefone" placeholder="Telefone">	    	    	
						</div>

				  	<br style="clear: both">
				    <input type="submit" value="Submit">
			  	</form>						
			</div>
		</section>
		<footer>
			Sistema desenvolvido por Rodrigo Henrique Ramos - 2020B
		</footer>
	</div>
	
	<script type="text/javascript" src="js/js.js"></script>
</body>
</html>