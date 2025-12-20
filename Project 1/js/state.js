export const state = {
  scene: "title",
  player: {
    x: 5,
    y: 5
  },
  xp: 0,
  level: 1,
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
  if (state.xp >= state.level * 100) {
    state.level += 1
  }
  saveProgress()
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
