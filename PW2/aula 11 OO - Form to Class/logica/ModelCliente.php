<?php

/**
 * Cliente
 */
class ModelCliente
{
	private $email;
	private $nome;
	private $senha;
	private $textao;
	
	function __construct()
	{
		echo "construtor vazio <br>";
	}

	function __destruct()
	{
		echo "destruct vazio <br>";
	}

	function __toString(){
		return 	$this->getEmail().';'.
				$this->getNome().';'.
				$this->getSenha().';'.
				$this->getTextao().'|';
	}

	function construtorPOST()
	{
		$this->setEmail($_POST["email"]);
		$this->setNome($_POST["nome"]);
		$this->setSenha($_POST["senha"]);
		$this->setTextao($_POST["textao"]);
	}



	/**
	 * Get the value of textao
	 */ 
	public function getTextao()
	{
		return $this->textao;
	}

	/**
	 * Set the value of textao
	 *
	 * @return  self
	 */ 
	public function setTextao($textao)
	{

		$this->textao = $textao;

		return $this;
	}

	/**
	 * Get the value of senha
	 */ 
	public function getSenha()
	{
		return $this->senha;
	}

	/**
	 * Set the value of senha
	 *
	 * @return  self
	 */ 
	public function setSenha($senha)
	{
		$this->senha = md5($senha);

		return $this;
	}

	/**
	 * Get the value of nome
	 */ 
	public function getNome()
	{
		return $this->nome;
	}

	/**
	 * Set the value of nome
	 *
	 * @return  self
	 */ 
	public function setNome($nome)
	{
		$this->nome = $nome;

		return $this;
	}

	/**
	 * Get the value of email
	 */ 
	public function getEmail()
	{
		return $this->email;
	}

	/**
	 * Set the value of email
	 *
	 * @return  self
	 */ 
	public function setEmail($email)
	{
		$this->email = $email;

		return $this;
	}
}