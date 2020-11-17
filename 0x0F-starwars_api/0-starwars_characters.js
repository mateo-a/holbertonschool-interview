#!/usr/bin/node
const request = require('request');

async function films (url) {
  request(url, async function (err, response, body) {
    if (err) {
      console.log(err);
    } else {
      for (const chars of JSON.parse(body).characters) {
        const ret = () => {
          return new Promise((resolve, reject) => {
            request(chars, function (err, response, body) {
              if (err) {
                console.log(err);
              } else {
                resolve(JSON.parse(body).name);
              }
            });
          });
        };
        console.log(await ret());
      }
    }
  });
}

if (process.argv.length === 3) {
  films(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}`);
}
