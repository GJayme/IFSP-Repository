<?php
	session_start();
	include("util.php");
	// debug($_SESSION);
	
	function valueInput($key){
		// echo isset($_SESSION[$key]) ? $_SESSION[$key] : '';
		if(isset($_SESSION[$key])){
			echo $_SESSION[$key];
		} else {
			echo '';
		}
	}

	function verificaCursos($curso){
		foreach($_SESSION['cursos'] as $c){
			if($curso == $c){
				echo "checked";
			}
		}
	}

	function verificaOption($pais){
		if($_SESSION['country'] == $pais){
			echo 'selected';
		}
	}

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
					<a href="exemploSession.php"><li>Página 2</li></a>
					<a href="#"><li>Página 3</li></a>
				</ul>
			</nav>
		</header>
		<section id="principal">
			<?php
				if (isset($_SESSION["senha"])) {
					$retorno = $_SESSION["senha"];
					echo "<div class='erro'>".$retorno."</div>";
				}else if(isset($_SESSION["msgSucesso"])) {
					// session_unset();
					$retorno = $_SESSION["msgSucesso"];
					echo "<div class='sucesso'>".$retorno."</div>";
				} else if (isset($_SESSION["msg"])) {
					$retorno = $_SESSION["msg"];
					$retorno = explode(";", $retorno);
					//remove o último elemento do array. Que sempre será vazio pq cada msg de erro termina com;
					array_pop($retorno);
					echo "<div class='erro2'>";
					echo "<ul>";
					foreach ($retorno as $key => $value) {
						echo "<li>".$value."</li>";
					}
					echo "<ul>";
					echo "</div>";
				}
			?>
			<div id="calculadora" class="contorno">
				<form action="recebeForm.php" method="POST">
					<div id="divFormEsq">
					    <label for="fname">Primeiro Name</label>
					    <input value="<?php valueInput("firstname") ?>" type="text" id="fname" name="firstname" placeholder="Primeiro nome">
					    
					    <label for="lname">Sobrenome</label>
					    <input value="<?php valueInput("lastname") ?>" type="text" id="lname" name="lastname" placeholder="Sobrenome">
					    
					    <label for="country">País</label>
					    <select id="country" name="country">
					      <option value="NULL"></option>	
					      <option <?php verificaOption("australia");?> value="australia">Australia</option>
					      <option <?php verificaOption("canada");?> value="canada">Canada</option>
					      <option <?php verificaOption("brasil");?> value="brasil">Brasil</option>
					      <option <?php verificaOption("usa");?> value="usa">USA</option>
					    </select>
					    <div style="float: left">
						    <label for="cursos">Cursos</label><br>
						    <input <?php verificaCursos("PHP");?> type="checkbox" name="cursos[]" value="PHP">PHP <br>
						    <input <?php verificaCursos("HTML");?> type="checkbox" name="cursos[]" value="HTML">HTML <br>
						    <input <?php verificaCursos("CSS");?> type="checkbox" name="cursos[]" value="CSS">CSS <br>
						</div>
				    </div>

				    <div id="divFormDir">
					    <label for="email">E-mail</label>
					    <input value="<?php valueInput("email") ?>" type="text" id="email" name="email" placeholder="E-mail">		    	

					    <label for="senha">Senha</label>
					    <input value="<?php valueInput("password") ?>" type="password" id="password" name="password" placeholder="Senha">
						
						<label for="telefone">Telefone</label>
					    <input value="<?php valueInput("telefone") ?>" type="text" id="telefone" name="telefone" placeholder="Telefone">

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

<?php //session_unset();?>