const APIkey = "Khp4lBmSGAgwQW3VSsFRh2OQLM6Fft82EVEkZW87";
var start_date_global = "";
var email = "";
var user_name = "";

(function () {
    document.addEventListener('DOMContentLoaded', function () {
        email = document.getElementById('email').innerHTML.trim();
        user_name = document.getElementById('userName').innerHTML.trim();
        document.getElementById('email').classList.add('d-none');
        document.getElementById('userName').classList.add('d-none');
        document.getElementById("start_date").value = getDateAsString(new Date) //sets the default date of today

        addListenersToDateButton();
    });

    /** Validates the status of the response
     * @param response response from the fetch
     * @returns Promise resolved or rejected
     */
    function status(response) {
        if (response.status >= 200 && response.status < 300)
            return Promise.resolve(response)
        else
            return Promise.reject(response)
    }

    /**
     * event listener to button 'Ok' and button 'more'
     */
    function addListenersToDateButton() {
        document.getElementById("button-date").addEventListener("click", function () {
            document.querySelector('#data').innerHTML = "";
            document.getElementById("table_pictures").innerHTML = "";
            document.getElementById("spinner").classList.remove('d-none');
            let date_chosen = document.getElementById("start_date").value;
            let date_start = new Date(date_chosen);
            date_start.setDate(date_start.getDate() - 2);
            fetchDataFromNasaApi(getDateAsString(date_start), date_chosen);
            start_date_global = getDateAsString(date_start);

            //button more
            document.getElementById("button more").innerHTML = `<button type="button" id="button-date-more" class="btn btn-primary">More</button>`;
            document.getElementById("button more").classList.remove('d-none');
            document.getElementById("button-date-more").addEventListener("click", function () {
                let date = new Date(start_date_global);
                date.setDate(date.getDate() - 3);
                let end_date_new = new Date(start_date_global);
                end_date_new.setDate(end_date_new.getDate() - 1);
                start_date_global = getDateAsString(date);
                document.getElementById("spinner_2").classList.remove('d-none');
                fetchDataFromNasaApi(getDateAsString(date), getDateAsString(end_date_new));
            });
        });
    }
    /** Fetches data from the NasaApi.
     * It gets the start date of the api and the end date to show the json needed.
     * @param start_date the start date of the url
     * @param end_date the end date of the url
     */
    function fetchDataFromNasaApi(start_date, end_date) {
        fetch('https://api.nasa.gov/planetary/apod?api_key=' + APIkey + "&start_date=" +
            start_date + "&end_date=" + end_date)
            .then(status)
            .then(res => res.json())
            .then(json => {
                for(let i = json.length - 1; i >= 0; i--) {
                    addImageToEJS(json[i]);
                    getCommentsFromCommentsApi(json[i].date);
                }
                document.getElementById("spinner").classList.add('d-none'); // remove the loading gif
                document.getElementById("spinner_2").classList.add('d-none'); // remove the loading gif
                return json;
            })
            .then(json => {
                //event listener to button comment
                setTimeout(() => {
                    for(let i = json.length - 1; i >= 0; i--) {
                        document.getElementById(`${json[i].date}-butT_comment`).addEventListener('click',function (){
                            postComment(json[i].date);
                        })
                    }
                }, 3000);
            })
            .catch(function(error) {
                if(error.status === 400) {
                    error.json().then(function (data) {
                        document.querySelector("#data").innerHTML = "Error Fetch nasaApi: " + data.msg;
                    })
                }
                else
                   document.querySelector("#data").innerHTML = "Error Fetch nasaApi: " + error;
                document.getElementById("button more").classList.add("d-none"); // remove button more
            })
    }

    /** gets a JSON of an APOD, adds a html code with data of the JSON to the page
     * @param img_data JSON of an APOD
     */
    function addImageToEJS(img_data) {
        let str = "";
        var imgPromise = loadImage(img_data.url);
        imgPromise.then(function (img) {
            str = `<div class="row">` +
                `<div class="col-5">` +
                `<div class="card" id='${img_data.date}-primary_description'>` +
                `<h3>${img_data.title}</h3>` +
                `<p>Date: ${img_data.date}</p>`;
            if(img.src.includes('youtube'))
                str+=`<iframe src="${img.src}" width="200" height="400"></iframe>`;
            else
                str += `<img src='${img.src}' alt="APOD" class='card-img-top' id='${img_data.date}-img' width="200" height="400">`;
            str += `</div>` +
                `</div>` +
                `<div class="col-4" xmlns="http://www.w3.org/1999/html">` +
                `<div class ="card" id='${img_data.date}-description'>` +
                `<h3>Description</h3>` +
                `<p><strong>copyright: </strong>${img_data.copyright}</p>` +
                `<p class="box">${img_data.explanation}</p>` +
                `<p><strong>Add a comment: </strong></p>` +
                `<textarea id='${img_data.date}-textarea' rows="3" maxlength="128" class="col-12" name="comment"></textarea>` +
                `<div id="${img_data.date}-divComm">` +
                `<button type="button" id="${img_data.date}-butT_comment" class="btn btn-primary col-4" name="${img_data.date}">Comment</button>` +
                `</div>` +
                `</div>` +
                `</div>` +
                `<div class="col-3">` +
                `<div class="card">` +
                `<h3>Comments</h3>` +
                `<div id='${img_data.date}-comments'>` +
                `</div>` +
                `</div>` +
                `</div>` +
                `</div>` +
                `<br>`;
            document.getElementById("table_pictures").innerHTML += str;
        })
            .catch(function(err){
                document.getElementById("data").innerHTML = "Error addImageToEJS: " + err;
            });
    }

    /** checks if it's an image url or youtube url,
     * and tries to load it if its successfully loaded then resolve else reject
     * @param url url of image or youtube
     * @returns Promise resolved or rejected
     */
    function loadImage(url){
        return new Promise(function(resolve, reject) {
            var img = new Image();
            if(url.includes('youtube')) {
                img.src = url;
                resolve(img)
            }
            else {
                img.src = url; // async - open connection
                img.onload = function () {
                    resolve(img)
                }
                img.onerror = function (e) {
                    reject("there was an error loading the image")
                }
            }
        });
    }
    /** gets a date of an img that's corresponds to the id of the image,
     * and fetches from our restApi the data needed
     * for adding the comments to the html page.
     * Adds also the delete button.
     * @param img_date the date of an img that's corresponds to the id of the image
     */
    function getCommentsFromCommentsApi(img_date) {
        fetch(`/nasa/nasa/${img_date}`)
            .then(status)
            .then(res => res.json())
            .then(data => {
                if (document.getElementById(`${img_date}-comments`) !== null)
                    document.getElementById(`${img_date}-comments`).innerHTML = "";
                for(let i = 0; i < data.length; i++) {
                    if (document.getElementById(`${data[i].date}-comments`) !== null) {
                        document.getElementById(`${data[i].date}-comments`).innerHTML +=
                            `<div class="alert alert-dark" id="${data[i].date}/${data[i].email}/${data[i].id}-div">` +
                            `<h5>${data[i].name}</h5>` +
                            `<p>${data[i].comment}</p>` +
                            `</div>`;
                        if (email === data[i].email) {
                            let delete_btn = document.createElement('button');
                            delete_btn.type = 'button';
                            delete_btn.setAttribute('id', `${data[i].date}/${data[i].email}/${data[i].id}`);
                            delete_btn.classList.add('btn', 'btn-danger');
                            delete_btn.textContent = 'Delete';
                            let div = document.getElementById(`${data[i].date}/${data[i].email}/${data[i].id}-div`);
                            div.appendChild(delete_btn);
                        }
                    }
                }
                return data;
            }).then(data => {
                addListenersToDeleteButtons(data);
        }).catch(function(error) {
            if(error.status === 500)
                location.href = '/logout';
            else {
                document.querySelector("#data").appendChild(document.createTextNode("Error Fetch: getCommentsFromCommentsApi " + error));
                document.getElementById("button more").classList.add("d-none");
            }
            });
    }
    /** function triggers when the comment button is pressed. Sends the comment to the restApi where it
     * adds to the data structure.
     */
    function postComment(date) {
        let data = {
            date : date,
            comment: document.getElementById(`${date}-textarea`).value,
            name: user_name,
            email: email
        }
        fetch("/nasa/post", {
            method: "POST",
            headers: {"Content-Type": "application/json"},
            body: JSON.stringify(data)
        })
            .then(status)
            .then(res => res.json())
            .then(data => {
                getCommentsFromCommentsApi(data.date);
        })
            .catch(function(err) {
                if(err.status === 500)
                    location.href = '/logout';
                else {
                    document.querySelector("#data").appendChild(document.createTextNode("Error Fetch: post comment" + err.toString()));
                    document.getElementById("button more").classList.add("d-none");
                }
            });
        document.getElementById(`${date}-textarea`).value = "";
    }

    /** Adding listeners to the delete buttons(deleting the comments).
     * @param data the data of the comment.
    */
    function addListenersToDeleteButtons(data)
    {
        for(let i = 0; i < data.length; i++) {
            if(document.getElementById(`${data[i].date}/${data[i].email}/${data[i].id}`) !== null) {
                let btn = document.getElementById(`${data[i].date}/${data[i].email}/${data[i].id}`);
                btn.addEventListener('click', function () {
                fetch(`/nasa/nasa/${data[i].id}`, {
                    method: 'DELETE',
                    headers: {"Content-Type": "application/json"},
                })
                    .then(status)
                    .then(res => res.json())
                    .then(res => {
                        let div = document.getElementById(`${data[i].date}/${data[i].email}/${data[i].id}-div`);
                        div.parentNode.removeChild(div);
                    })
                    .catch(function (err) {
                        if(err.status === 500)
                            location.href = '/logout';
                        else
                            document.querySelector("#data").appendChild(document.createTextNode("Error Fetch Delete: " + err));
                    });
                })
            }
        }
    }
    /** gets a Date object and returns as string the
     * @param date a Date object
     * @returns string of date
     */
    function getDateAsString(date) {
        let day = date.getDate();
        let month = date.getMonth() + 1;
        let year = date.getFullYear();
        if (month < 10) month = "0" + month;
        if (day < 10) day = "0" + day;
        return year + "-" + month + "-" + day;
    }
})();