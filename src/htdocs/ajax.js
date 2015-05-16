function ajaxRequest(method, addr, data, callback)
{
	// Create a communications object.
	var xmlhttp = (window.XMLHttpRequest) ? new XMLHttpRequest() : new ActiveXObject("Microsoft.XMLHTTP");
    
	xmlhttp.onreadystatechange = function() {
		if (xmlhttp.readyState == 4)
			callback(xmlhttp);
	}
	xmlhttp.open(method, addr, true); 
	xmlhttp.send(data);
}

function ajaxFinish(x)
{
	var div = document.getElementById("response");
	div.innerHTML = "<b>Raw output:</b><br />";
	div.innerHTML += x.status+" "+x.statusText +" HTTP/1.0<br />";
	div.innerHTML += x.getAllResponseHeaders();
	div.innerHTML += "<br />" + x.responseText;
}

function getFile()
{
	var file = document.getElementById("file").value;
	if (file.length == 0 || /^\s+$/.test(file))
	{
		alert("enter filename");
		return false;
	}
	return file;
}

function newTab()
{
	var url = getFile();
	if (!url)
		return;
	var win=window.open(url, '_blank');
	win.focus();
}

function ajaxPut()
{
	var file = getFile();
	var data = document.getElementById("content").value;	
	if (file)
		ajaxRequest("PUT", file, data, ajaxFinish);
}

function ajaxDelete()
{
	var file = getFile();
	if (file)
		ajaxRequest("DELETE", file, "", ajaxFinish);
}

function ajaxHead()
{
	var file = getFile();
	if (file)
		ajaxRequest("HEAD", file, "", ajaxFinish);
}

function ajaxGet()
{
	var file = getFile();
	if (file)
		ajaxRequest("GET", file, "", ajaxFinish);
}
