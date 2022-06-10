const express = require("express");
const app = express();
const path = require("path");
const port = process.env.PORT || 80;
const staticpath = path.join(__dirname, "/");

var antares = require("antares-http");

app.use(express.static(staticpath));

app.get("/", function (req, res) {
  res.sendFile(staticpath + "/index.html");
});

app.get("/api", function (req, res) {
  antares.setAccessKey("8fe0cf53bf23dba6:07dc7b12f54bcc93");
  antares.get("smartplan", "sensor").then(function (response) {
    const data = response.content;
    res.json(data);
    console.log(data)
  });
});

app.listen(port);
