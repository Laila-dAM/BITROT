import { state } from "./state.js"
import { renderText } from "./renderer.js"

let baseMap = []

export function setMap(content) {
  baseMap = content.split("\n")
  draw()
}

export function draw() {
  const map = baseMap.map(line => line.split(""))

  const x = state.player.x
  const y = state.player.y

  if (map[y] && map[y][x]) {
    map[y][x] = "( •_• )"
  }

  const output = map.map(line => line.join("")).join("\n")
  renderText(output)
}
