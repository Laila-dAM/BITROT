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
  saveProgress()
}

export function movePlayer(x, y) {
  state.player.x = x
  state.player.y = y
  saveProgress()
}

export function addXP(value) {
  state.xp += value

  while (state.xp >= state.level * 100) {
    state.level += 1
  }

  saveProgress()
}

export function saveProgress() {
  localStorage.setItem("gameState", JSON.stringify(state))
}

export function loadProgress() {
  const saved = localStorage.getItem("gameState")
  if (!saved) return

  const parsed = JSON.parse(saved)

  Object.assign(state, parsed)
  state.flags ||= {}
  state.inventory ||= []
  state.player ||= { x: 0, y: 0 }
}

export function setFlag(name) {
  state.flags[name] = true
  saveProgress()
}

export function hasFlag(name) {
  return state.flags[name] === true
}

export function isGameOver() {
  return state.flags.chose_escape === true && state.xp < 20
}
