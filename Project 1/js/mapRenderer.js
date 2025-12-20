import { state } from "./state.js"
import { renderText } from "./renderer.js"
import { getNPCAt } from "./npc.js"

let baseMap = []

export function setMap(content) {
  baseMap = content.split("\n")
  draw()
}

export function getTile(x, y) {
  if (!baseMap[y] || !baseMap[y][x]) return null
  return baseMap[y][x]
}

export function isBlocked(x, y) {
  const tile = getTile(x, y)
  if (!tile) return true
  return tile === "⣿"
}

export function draw() {
  const map = baseMap.map(line => line.split(""))

  for (let y = 0; y < map.length; y++) {
    for (let x = 0; x < map[y].length; x++) {
      const npc = getNPCAt(x, y)
      if (npc) {
        map[y][x] = "૮₍ ˶ᵔ ᵕ ᵔ˶ ₎ა"
      }
    }
  }

  const px = state.player.x
  const py = state.player.y

  if (map[py] && map[py][px]) {
    map[py][px] = "( •_• )"
  }

  const output = map.map(line => line.join("")).join("\n")
  renderText(output)
}
