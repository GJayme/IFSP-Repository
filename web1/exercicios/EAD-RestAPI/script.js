let getPrograms = (data) => {
  $("table").empty();
  for (i in data) {
    $("table").append(`
      <thead>
        <tr>
          <td>Nome</td>
          <td>Tipo de programação</td>
          <td>Idioma</td>
        </tr>
      </thead>
      <tbody>
        <tr>
          <td>${data[i].show.name}</td>
          <td>${data[i].show.type}</td>
          <td>${data[i].show.language}</td>
          <td>
            <button idEpisodies=${data[i].show.id} id="buttonEpisodies">Buscar</button>
          </td>
        </tr>
      </tbody>
    `)
  }
}

let getEpisodies = (data) => {
  $("table").empty();
  for (i in data) {
    $("table").append(`
      <thead>
        <tr>
          <td>Número do Capítulo</td>
          <td>Número da Temporada</td>
          <td>Data de exibição</td>
        </tr>
      </thead>
      <tbody>
        <tr>
          <td>${data[i].number}</td>
          <td>${data[i].season}</td>
          <td>${data[i].airdate}</td>
        </tr>
      </tbody>
    `)
  }
}


$(document).on("click", "#searchButton", (event) => {
  event.preventDefault();

  let programSearch = $("#programa").val()

  $.ajax({
    url: `http://api.tvmaze.com/search/shows?q=${programSearch}`,
    type: "GET",
    success: function (data) {
      if (data.length === 0) {
        alert("Nenhum programa encontrado!")
      }
      getPrograms(data)
    }
  })
})

$(document).on("click", "#buttonEpisodies", function () {

  let idEpisodies = $(this).attr('idEpisodies')

  $.ajax({
    url: `http://api.tvmaze.com/shows/${idEpisodies}/episodes`,
    type: "GET",
    success: function (data) {
      getEpisodies(data)
    }
  })
})