setInterval(function () {
    fetch("https://smartstick.herokuapp.com/api")
      .then((hasil) => hasil.json())
      .then((res) => {
        console.log(res);
        document.getElementById("hambatan").innerHTML = res.detected;
      });
  }, 1000);

