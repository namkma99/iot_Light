const char webpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="preconnect" href="https://fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css2?family=Open+Sans:wght@700;800&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.3/css/all.min.css"
        integrity="sha512-iBBXm8fW90+nuLcSKlbmrPcLa0OT92xO1BIsZ+ywDWZCvqsWgccV3gFoRBv0z+8dLJgyAHIhR35VZc2oM/gI1w=="
        crossorigin="anonymous" />

</head>

<body>
    <style>
        * {
            margin: 0;
            padding: 0;
            font-family: 'Open Sans', sans-serif;
        }

        .app {
            position: relative;
        }

        .dashbord {
            background: rgb(228, 116, 116);
            height: 72px;
            width: 100%;
            color: #fff;
            font-size: 32px;
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .nav .sidebar {
            position: absolute;
            width: 240px;
            height: 100vh;
            background: chartreuse;
            transition: 0.25s ease-in-out;
            animation: animationOpen;
            /* padding-left: 16px;
            padding-right: 16px; */
        }

        .menuSidebar {}

        .menu {
            display: flex;
            justify-content: space-between;
            align-items: center;
            padding: 16px 24px;
            border-bottom: 1px solid #333;
            font-size: 24px;
        }

        .menu.on {
            border: none;
        }

        .menuOpen,
        .menuOpen1 {
            display: none;
        }

        .menuClose {
            animation: animationText 0.25s ease-in-out;
        }

        .menuSidebar .itemSidebar {
            list-style: none;
            padding: 16px 24px;
        }

        .menuSidebar .itemSidebar:hover {
            background: blueviolet;
        }

        .textMenu {
            /* transition: ; */
            animation: animationText 0.5s ease-in-out;
        }

        .itemSidebar_link {
            text-decoration: none;
            /* justify-content: center; */
        }

        .itemSidebar_link-block {
            display: flex;
            animation: animationText 0.25s ease-in-out;
        }

        .itemSidebar_link-block .icon {
            padding-right: 16px;
        }

        @keyframes animationText {
            from {
                left: -240px;
                opacity: 0;
            }

            to {
                left: 0px;
                opacity: 1;
            }
        }

        /* content */
        .content {
            margin-left: 240px;
            margin-top: 5px;
            transition: 0.25s ease-in-out
        }

        .content .content_list {
            margin-left: 5px;
            padding: 16px;
            background: rgb(200, 200, 200);

        }

        .content_list {
            display: none;
        }

        .content_list.active {
            display: block;
        }

        .state_lamp {
            font-size: 32px;
        }

        .state_lamp_list .state_item {
            list-style: none;
            text-transform: uppercase;
        }

        /* toggle */
        /* elementClose */
        .nav .elementClose {
            width: 72px;
            animation: animationOpen 0.15s ease-in-out;
        }

        @keyframes animationOpen {
            from {
                left: 0;
                /* transition: 0.25 ease-in-out; */
            }

            to {
                left: 0;
                /* transition: 0.25 ease-in-out; */
                opacity: 1;
            }
        }

        .elementClose .textMenu {
            display: none;
        }

        .elementClose .menu {
            display: flex;
            justify-content: center;
        }

        .elementClose .itemSidebar {
            padding: 16px 0;
            display: flex;
            justify-content: center;
        }

        .elementClose .icon {
            display: flex;
            justify-content: center;
            margin-bottom: 8px;
        }

        /* contentToggle */
        .contentToggle {
            margin-left: 72px;
            /* display: none; */
        }

        .itemSidebar.active {
            background-color: crimson;
            border-left: 8px solid blueviolet;
        }

        /*  */
        .lamp_content {
            display: flex;
            position: relative;
        }

        .list_content {
            display: flex;
        }

        .btn-lamp {
            position: absolute;
            right: 0;
            top: -15px;
        }

        .lightbulb {
            background-image: url(https://upload.wikimedia.org/wikipedia/commons/6/64/Simple_light_bulb_graphic.png);
            background-size: 100px;
            height: 100px;
            background-repeat: no-repeat;
            width: 100px;
            background-clip: content-box;
            border-radius: 50%;
        }

        .btn-leftt-right {
            width: 70px;
            height: 30px;
            background-color: rgb(126, 126, 126);
            border-radius: 24px;
            position: relative;
        }

        .btn-icon {
            width: 40px;
            height: 22px;
            background: rgb(202, 202, 202);
            border-radius: 24px;
            position: absolute;
            left: 25px;
            top: 4px;
            border: none;
            outline: none;
        }

        .list_content {
            display: none;
        }

        .list_content.on {
            display: inline-flex;
        }

        .btn-icon.on {
            left: 5px;
        }

        .color {
            background-color: rgb(52, 52, 230);
        }

        .main {
            height: 400px;
            width: 250px;
            background: #333;
            border-radius: 10px;
            display: grid;
            place-items: center;
            color: #fff;
            font-family: Verdana;
            margin-left: 100px;
        }

        #box {
            height: 40px;
            width: 80%;
            border: none;
            outline: none;
            border-radius: 50px;
            text-align: center;
            color: #ffffff;
            font-size: 24px;
        }

        input[type="range"] {
            -webkit-appearance: none;
            height: 10px;
            width: 80%;
            outline: none;
            border-radius: 10px;
        }

        input[type="range"]::-webkit-slider-thumb {
            -webkit-appearance: none;
            height: 25px;
            width: 25px;
            background: #fff;
            border-radius: 50%;
            cursor: pointer;
            left: 0;
        }

        .main #red {
            background: linear-gradient(90deg, #000, red);
        }

        .main #green {
            background: linear-gradient(90deg, #000, green);
        }

        .main #blue {
            background: linear-gradient(90deg, #000, blue);
        }

        /* modal */
        .nav_modal .sidebar {
            position: absolute;
            top: 72px;
            left: 0;
            width: 240px;
            background: chartreuse;
            transition: 0.25s ease-in-out;
            animation: animationOpen;
            height: 100vh;
            display: none;
        }

        @media only screen and (max-width: 1024px) {

            .menuOpen,
            .menuClose,
            .textMenu {
                display: none !important;
            }

            .menuOpen1 {
                display: block;
            }

            .menuOpen1.none {
                display: none;
            }

            .nav .sidebar {
                width: 72px;
            }

            .itemSidebar {
                padding: 16px 0;
                display: flex;
                justify-content: center;
            }

            .content {
                margin-left: 72px;
            }

            .itemSidebar_link {
                display: inline-block;
            }

            .itemSidebar_link-block .icon {
                display: flex;
                padding: 0;
                justify-content: center;
            }

            /* modal */
            .modal_Sidebar.on {
                display: block;
            }

            .modal_menuSidebar .itemSidebar {
                display: block;
                list-style: none;
                padding: 16px 24px;
                border-bottom: 1px solid #333;
            }
        }
        
    </style>
    <div class="app">
        <header>
            <div class="dashbord">
                ADMIN DASHBORD
            </div>
            <div class="nav">
                <div class="sidebar">
                    <div class="menu ">
                        <span class=" menuOpen1"><i class="fas fa-align-left"></i></span>
                        <span class=" menuOpen"><i class="fas fa-align-left"></i></span>
                        <span class=" menuClose"><i class="fas fa-align-right"></i></span>
                        <span class="textMenu">MENU</span>
                        <span class="menuClose menuClose2"><i class="fas fa-times"></i></span>
                    </div>
                    <ul class="menuSidebar ">
                        <li class="itemSidebar active">
                            <a href="#" class="itemSidebar_link itemSidebar_link-block">
                                <div class="icon">
                                    <i class="fas fa-home"></i>
                                </div>
                                <div>HOME</div>
                            </a>
                        </li>
                        <li class="itemSidebar">
                            <a href="#" class="itemSidebar_link itemSidebar_link-block">
                                <div class="icon">
                                    <i class="fas fa-chart-pie"></i>
                                </div>
                                <div>CHART</div>
                            </a>
                        </li>
                        <li class="itemSidebar">
                            <a href="#" class="itemSidebar_link itemSidebar_link-block">
                                <div class="icon">
                                    <i class="fas fa-adjust"></i>
                                </div>
                                <div>LAMP</div>
                            </a>
                        </li>
                    </ul>
                </div>
            </div>
        </header>
        <div class="content">
            <div class="home content_list active">
                <div class="home_content">
                    <div class="state_lamp">
                        <ul class="state_lamp_list">
                            <li class="state_item">
                                trạng thái đèn:
                                <span class="state_on">Tắt</span>
                            </li>
                            <li class="state_item">
                                <span>số giờ sáng:</span>
                            </li>
                            <li class="state_item">
                                <span>thời gian còn lại:</span>
                            </li>
                        </ul>
                    </div>
                </div>
            </div>
            <div class="chart content_list ">
                Chart
            </div>
            <div class="lamp content_list">
                <div class="lamp_content">
                    <div class="list_content">
                        <div class="lightbulb"></div>
                        <div class="main">
                            result: <input type="text" id="box" min="0" max="250" disabled value="0, 0, 0">
                            red: <input type="range" id="red" min="0" max="250" value="rgb(0,0,0)">
                            green: <input type="range" id="green" min="0" max="250" value="rgb(0,0,0)">
                            blue: <input type="range" id="blue" min="0" max="250" value="rgb(0,0,0)">
                        </div>
                    </div>
                    <div class="btn-lamp">
                        <div class="btn-leftt-right">
                            <button class="btn-icon on"></button>
                        </div>
                    </div>
                </div>

            </div>
        </div>
        <div class="modal_SidebarMenu">
            <div class="nav_modal">
                <div class="sidebar modal_Sidebar">
                    <div class="menu ">
                        <span class=" modal_menuClose"><i class="fas fa-align-right"></i></span>
                        <span class=" modal_textMenu">MENU</span>
                        <span class=" modal_menuClose menuClose2"><i class="fas fa-times"></i></span>
                    </div>
                    <ul class="menuSidebar modal_menuSidebar">
                        <li class="itemSidebar active">
                            <a href="#" class="itemSidebar_link itemSidebar_link-block">
                                <div class="icon">
                                    <i class="fas fa-home"></i>
                                </div>
                                <div>HOME</div>
                            </a>
                        </li>
                        <li class="itemSidebar">
                            <a href="#" class="itemSidebar_link itemSidebar_link-block">
                                <div class="icon">
                                    <i class="fas fa-chart-pie"></i>
                                </div>
                                <div>CHART</div>
                            </a>
                        </li>
                        <li class="itemSidebar">
                            <a href="#" class="itemSidebar_link itemSidebar_link-block">
                                <div class="icon">
                                    <i class="fas fa-adjust"></i>
                                </div>
                                <div>LAMP</div>
                            </a>
                        </li>
                    </ul>
                </div>
            </div>
        </div>

    </div>
    <script>
        var menu = document.querySelector('.menu')
        var closeSidebar = document.querySelectorAll('.menuClose');
        var openSidebar = document.querySelector('.menuOpen');
        var itemSideLink = document.querySelectorAll('.itemSidebar_link')
        var content = document.querySelector('.content')
        var sidebar = document.querySelector('.sidebar');

        closeSidebar.forEach(element => {
            element.addEventListener('click', function (e) {
                menu.classList.add('on')
                sidebar.classList.toggle('elementClose');
                if (e.target) {
                    content.classList.add('contentToggle');
                    closeSidebar.forEach(e => e.style.display = 'none')
                    openSidebar.style.display = 'block';
                    itemSideLink.forEach(e => e.classList.remove('itemSidebar_link-block'));
                }
            })
        })
        openSidebar.addEventListener('click', function (e) {
            menu.classList.remove('on')
            sidebar.classList.toggle('elementClose');
            closeSidebar.forEach(e => e.style.display = 'block');
            content.classList.remove('contentToggle');
            openSidebar.style.display = 'none'
            itemSideLink.forEach(e => e.classList.add('itemSidebar_link-block'))
        })

        var btns = document.querySelectorAll('.itemSidebar');
        btns.forEach((tab, index) => {
            let panes = document.querySelectorAll('.content_list');
            const pane = panes[index];
            tab.onclick = function () {
                btns.forEach(e => e.classList.remove('active'))
                panes.forEach(e => e.classList.remove('active'))
                this.classList.add('active')
                pane.classList.add('active');
            }
        })
        // lamp
        document.getElementById('red').addEventListener('input', myColor);
        document.getElementById('green').addEventListener('input', myColor);
        document.getElementById('blue').addEventListener('input', myColor);
        function myColor() {
            var lightbulb = document.querySelector('.lightbulb');
            // var xhttp = new XMLHttpRequest();
            // xhttp.open('GET','RGB', true);
            // xhttp.send();
            var red = document.getElementById('red').value;
            var green = document.getElementById('green').value;
            var blue = document.getElementById('blue').value;
            var color = 'rgb(' + red + ',' + green + ',' + blue + ')';
            lightbulb.style.backgroundColor = color;
            document.getElementById('box').value = red + ',' + green + ',' + blue;
            console.log(red)
        }

        let btnClick = document.querySelector('.btn-leftt-right');
        btnClick.onclick = function (e) {
            let state_lamp = document.querySelector('.state_item .state_on')
            let btnIcon = document.querySelector('.btn-icon');
            let listContent = document.querySelector('.list_content');
            let stateList = document.querySelector('.list_content');
            btnIcon.classList.toggle('on')
            btnClick.classList.toggle('color')
            listContent.classList.toggle('on')
            if (!btnIcon.classList.contains('on')) {
                state_lamp.innerHTML = 'BẬT'
            } else {
                state_lamp.innerHTML = 'TẮT'

            }
            // console.log(btnIcon.style)
        }
        // modal 
        var modalMenuOpen1 = document.querySelector('.menuOpen1');
        var modalSidebar = document.querySelector('.modal_Sidebar');
        modalMenuOpen1.onclick = function () {
            // console.log(modalSidebar)
            modalSidebar.classList.add('on');
            modalMenuOpen1.classList.add('none')
        }
        var modalMenuClose = document.querySelectorAll('.modal_menuClose');
        modalMenuClose.forEach(click => {
            click.onclick = function () {
                modalSidebar.classList.remove('on');
                modalMenuOpen1.classList.remove('none')
            }
        })
    </script>
</body>

</html>
)=====";
