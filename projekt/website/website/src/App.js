import React, { Component } from 'react'
import * as firebase from "firebase"
import ReactEcharts from 'echarts-for-react'

class App extends Component {
  constructor(props) {
    super(props)

    var config = {
      apiKey: "AIzaSyDCM7uLRtAfGas80W720SZRPhkX2lBqF70",
      authDomain: "swe2-projekt.firebaseapp.com",
      databaseURL: "https://swe2-projekt.firebaseio.com",
      projectId: "swe2-projekt",
      storageBucket: "swe2-projekt.appspot.com",
      messagingSenderId: "830812853062"
    }
    firebase.initializeApp(config)

    this.state = {}

    firebase.database().ref('/data/').on('value', snapshot => {
      const values = snapshot.val()
      const data = []
      const xVals = []

      if (values == null || Object.keys(values) == null) {
        this.setState({ data: [], xValues: [] })
        return
      }

      Object.keys(values).forEach(dataKey => {
        data.push(values[dataKey].value)
        xVals.push(values[dataKey].time)
      })

      this.setState({ data: data, xValues: xVals })
    })
  }

  render() {
    console.log(this.state.data, this.state.xValues)

    return (
      <div style={{ fontFamily: 'Sans-Serif' }}>
        <div style={{ marginLeft: -100 }}>
          <ReactEcharts
            option={{
              color: ['red', 'blue'],
              grid: {
                show: true
              },
              tooltip: {
                trigger: 'axis'
              },
              title: {
                text: 'Messdaten',
                padding: [25, 0, 0, 125]
              },
              xAxis: {
                type: 'category',
                data: this.state.xValues,
                boundaryGap: false
              },
              yAxis: {
                type: 'value'
              },
              series: [{
                data: this.state.data,
                type: 'line'
              }]
            }}
            style={{ height: 500, width: '100%' }}
          />
        </div>
        <div style={{ position: 'absolute', right: 20, top: 30 }}>
          <div style={{ display: 'flex', flexDirection: 'column' }}>
            <img
              height={95}
              width={110}
              src={'http://www.publicmarketing.eu/_data/FH_Salzburg_Logo_2017.jpg'} alt='FH_logo'
            />
            <button
              style={{ marginTop: 10 }}
              onClick={() => firebase.database().ref('/data/').set(null)}
            >
              Clear Data
            </button>
          </div>
        </div>
        <div style={{ position: 'absolute', bottom: 10, right: 50 }}>
          &#9400; Maximilian Pichler
        </div>
      </div>
    )
  }
}

export default App
