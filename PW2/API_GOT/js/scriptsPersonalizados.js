// Global
let listaLivrosInfo;

$.ajax({
  url: "https://www.anapioficeandfire.com/api/books",
  type: "GET",
  dataType: "html",
})
  .done(function (resposta) {
    listaLivrosInfo = JSON.parse(resposta);
    //console.log(listaPersonagensInfo);
    escreveLivrosComoLista();
  })
  .fail(function (jqXHR, textStatus) {
    console.log("Request failed: " + textStatus);
  });

function escreveLivrosComoLista() {
  for (var i = 0; i < listaLivrosInfo.length; i++) {
    let nome = listaLivrosInfo[i].name;
    let numPersonagens = listaLivrosInfo[i].characters.length;

    $("#listaLivros").append(
      `
        <div class="col-md-6 col-lg-4 mb-5">
            <h1 class="centralizado">${nome}</h1>
            <div
            class="portfolio-item mx-auto"
            onclick="chamaModal(${i})"
            >
            <div class="portfolio-item-caption d-flex align-items-center justify-content-center h-100 w-100">
                <div class="portfolio-item-caption-content text-center text-white">
                <i class="fas fa-plus fa-3x"></i>
                </div>
            </div>
            <img  style="width: 332px" class="img-fluid" src="assets/img/${nome}.jpg" alt="" />
            </div>
        </div>
        `
    );
  }
}

function chamaModal(idDoLivroNalista) {
  console.log(listaLivrosInfo[idDoLivroNalista].name);

  $("#portfolioModal1Label").html(listaLivrosInfo[idDoLivroNalista].name);

  $("#portfolioModal1").modal();
}
