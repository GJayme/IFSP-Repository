<?php
session_start();
session_unset();
include("util.php");

// foreach($_POST as $key => $value) {
// 	$_SESSION[$key]=$_POST[$key];
// }

$_SESSION=$_POST;

if($_POST["firstname"]===$_POST["password"]){
	$_SESSION['senha'] = "Informe uma senha mais segura";
	header("Location:index.php?");
}else{
	$_SESSION['msg'] = "";
	if ($_POST["firstname"]=="") {
		$_SESSION['msg'] .= "Informe o primeiro nome;";
	}
	if ($_POST["lastname"]=="") {
		$_SESSION['msg'] .= "Informe o último nome;";
	}
	if ($_POST["country"]=="NULL") {
		$_SESSION['msg'] .= "Informe um pais;";
	}
	if ($_POST["email"]=="") {
		$_SESSION['msg'] .= "Informe um email;";
	}
	if ($_POST["password"]=="") {
		$_SESSION['msg'] .= "Informe uma senha;";
	}
	if ($_POST["telefone"]=="") {
		$_SESSION['msg'] .= "Informe um telefone;";
	}
	if (!isset($_POST["cursos"])) {
		$_SESSION['msg'] .= "Escolha pelo menos um curso;";
	}
	//Se a msgErro estiver vazia é pq deu tudo certo
	if($_SESSION==""){
		$_SESSION['msgSucesso'] = "Cadastrado com sucesso!";
		header("Location:index.php");
	}else{
		header("Location:index.php");
	}
	
}




