"""Plotly test."""
# 以下の2つをインポート
import plotly.offline as offline
import plotly.graph_objs as go

trace0 = go.Scatter(
                    x=[1, 2, 3, 4],
                    y=[10, 15, 13, 17]
                    )
trace1 = go.Scatter(
                    x=[1, 2, 3, 4],
                    y=[16, 5, 11, 10]
                    )
data = [trace0, trace1]

# オフラインでプロット
offline.plot(data, filename='basic-line.html', auto_open=True)
