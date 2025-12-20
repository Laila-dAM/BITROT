export const state = {
  scene: "title",
  player: {
    x: 0,
    y: 0
  },
  xp: 0,
  status: "STABLE",
  inventory: [],
  flags: {}
}

export function setScene(name) {
  state.scene = name
}

export function movePlayer(x, y) {
  state.player.x = x
  state.player.y = y
}

export function addXP(value) {
  state.xp += value
}

export function setStatus(value) {
  state.status = value
}

export function saveProgress() {
  localStorage.setItem("gameState", JSON.stringify(state))
}

export function loadProgress() {
  const saved = localStorage.getItem("gameState")
  if (saved) {
    Object.assign(state, JSON.parse(saved))
  }
}
