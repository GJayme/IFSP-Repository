<!DOCTYPE html>
<html>
<head>
	<title>PHP com OO</title>
	<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
</head>
<body style="background-color:#aaa;padding: 50px;">
	<div class="container">
  <div class="row">
    <div class="col-sm">
    </div>
    <div class="col-sm">	
		<h1 style="text-align: center">PHP com OO populado com form</h1>
		<form method="POST" action="logica/1_recebeForm.php" style="margin-top: 25px; background-color:#ddd;padding: 10px " >
			<h3>Cadastro cliente</h3>
		  <div class="form-group">
		    <label for="exampleFormControlInput1">Email</label>
		    <input type="text" class="form-control" id="exampleFormControlInput1" placeholder="name@example.com" name="email">
		  </div>
		  <div class="form-group">
		    <label for="exampleName">Nome</label>
		    <input type="text" class="form-control" id="exampleName" placeholder="Seu nome" name="nome">
		  </div>
		  <div class="form-group">
		    <label for="examplePassword">Senha</label>
		    <input type="password" class="form-control" id="exampleName" placeholder="Sua senha" name="senha">
		  </div>
		  
		  
		  <div class="form-group">
		    <label for="exampleFormControlTextarea1">Descrição</label>
		    <textarea class="form-control" id="exampleFormControlTextarea1" rows="3" name="textao"></textarea>
		  </div>
		  <input type="submit" class="btn-danger" name="" value="Enviar">
		</form>
    </div>
    <div class="col-sm">
    </div>
  </div>
</div>
</body>
</html>