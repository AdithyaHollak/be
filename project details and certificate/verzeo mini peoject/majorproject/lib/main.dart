import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

void main() {
  runApp(const MaterialApp(
    title: 'Major project',
    home: FirstPage(),
  ));
}

class FirstPage extends StatelessWidget {
  const FirstPage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: const Text('MainPage'),
        ),
        body: Center(
            child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            const Text('ADITHYA HOLLa K',
                style: TextStyle(fontSize: 40, fontStyle: FontStyle.italic, color: Colors.indigoAccent)),
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Padding(
                  padding: EdgeInsets.all(16),
                  child: ElevatedButton(
                    child: const Text('Introduction'),
                    onPressed: () {
                      Navigator.push(
                        context,
                        MaterialPageRoute(
                            builder: (context) => const IntroductionPage()),
                      );
                    },
                  ),
                ),
                Padding(
                  padding: EdgeInsets.all(16),
                  child: ElevatedButton(
                    child: const Text('Education'),
                    onPressed: () {
                      Navigator.push(
                        context,
                        MaterialPageRoute(
                            builder: (context) => const EducationPage()),
                      );
                    },
                  ),
                ),
                Padding(
                  padding: EdgeInsets.all(16),
                  child: ElevatedButton(
                    child: const Text('Skills'),
                    onPressed: () {
                      Navigator.push(
                        context,
                        MaterialPageRoute(
                            builder: (context) => const SkillPage()),
                      );
                    },
                  ),
                ),
              ],
            )
          ],
        )));
  }
}

class IntroductionPage extends StatelessWidget {
  const IntroductionPage({Key? key}) : super(key: key);
  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: const Text('IntroductionPage'),
        ),
        body: Center(
            child: Column(children: <Widget>[
          const Text(
              " I am ADITHYA HOLLA K . We are 10 members in my family including me. I am native to Kundapur."" Currently , I am purusing 3rd year at NMAMIT "
                  "and my graduation is about to complete in next couple of years.""My strengths are my analytical approach, my appreciable communication,and"
                  " presentation skills. ""I believe in being realistic. ",
              style: TextStyle(fontSize: 18, fontStyle: FontStyle.normal)),
          Padding(
            padding: EdgeInsets.all(280),
            child: ElevatedButton(
              onPressed: () {
                Navigator.pop(context);
                // //
              },
              child: const Text('Go back!'),
            ),
          ),
        ])));
  }
}

class EducationPage extends StatelessWidget {
  const EducationPage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: const Text('Education Page'),
        ),
        body: Center(
            child:
                Column( children: <
                    Widget>[
          const Text(
              '   As I compled my sslc in Sri Venkataramana English Medium school which is held in kundapur. I completed my sslc in 2017 by scoring 96%. I completed my puc in Excellent Pu College which was held in Sunnari . I passout in 2019 by scoring 95% . I took Biology as my subject in puc. I joined NMAMIT nitte in 2019 by taking Computer Science Engineering .'
              'Now I am pursing 3rd year. I score 9.34 as Sgpa in my fifth sem.',
              style: TextStyle(fontSize: 22, fontStyle: FontStyle.normal)),
          Center(
              child: Column(children: <Widget>[
            Container(
              margin: EdgeInsets.all(20),
              child: Table(
                defaultColumnWidth: FixedColumnWidth(120.0),
                border: TableBorder.all(
                    color: Colors.black, style: BorderStyle.solid, width: 2),
                children: [
                  TableRow(children: [
                    Column(children: [
                      Text('Course/Degree', style: TextStyle(fontSize: 20.0))
                    ]),
                    Column(children: [
                      Text('Name of school and college',
                          style: TextStyle(fontSize: 20.0))
                    ]),
                    Column(children: [
                      Text('Grade obtained', style: TextStyle(fontSize: 20.0))
                    ]),
                    Column(children: [
                      Text('Year of a passing',
                          style: TextStyle(fontSize: 20.0))
                    ]),
                  ]),
                  TableRow(children: [
                    Column(children: [Text('3rd year BE')]),
                    Column(children: [Text('NMAMIT , Nitte')]),
                    Column(children: [Text('8.8')]),
                    Column(children: [Text('pursuing')]),
                  ]),
                  TableRow(children: [
                    Column(children: [Text('Pre University')]),
                    Column(children: [Text('Excellent Pu College ,Sunnari')]),
                    Column(children: [Text('95%')]),
                    Column(children: [Text('2019')]),
                  ]),
                  TableRow(children: [
                    Column(children: [Text('SSLC')]),
                    Column(children: [
                      Text('Sri Venkataramana English Medium School , Kundapur')
                    ]),
                    Column(children: [Text('96%')]),
                    Column(children: [Text('2017')]),
                  ]),
                ],
              ),
            ),
          ])),
          Padding(
            padding: EdgeInsets.all(100),
            child: ElevatedButton(
              onPressed: () {
                Navigator.pop(context);
                // //
              },
              child: const Text('Go back!'),
            ),
          ),
        ])));
  }
}

class SkillPage extends StatelessWidget {
  const SkillPage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: const Text('Skill Page'),
        ),
        body: Center(
            child: Column(children: <Widget>[
              const Text(' I  have skills like:''Leadership experience ,''Communication skills ,''Organizational skills ,''Time management ,'
                  'Computer profiency,''Problem  Solving skills,''Team work and collaboration ,''Criticalthinking,''Interpersonal skills,'
                   'Working well.',
                  style: TextStyle(fontSize: 20, fontStyle: FontStyle.normal)),
              Padding(
                padding: EdgeInsets.all(285),
                child: ElevatedButton(
                  onPressed: () {
                    Navigator.pop(context);
                    // //
                  },
                  child: const Text('Go back!'),
                ),
              ),
            ])));
  }
}
